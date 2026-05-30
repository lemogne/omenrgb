#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/time.h>
#include <math.h>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <iostream>

const int ZONE_N = 4;
char buffer[256] = {0};
int fd = 0;
std::string path;
std::string zones_path = "/sys/devices/platform/hp-wmi/rgb_zones/";
std::string anim_path = "/.config/omenrgb/animations.cfg";
std::string palette_path = "/.config/omenrgb/palettes.cfg";
int zone_fd[ZONE_N];

struct animation_step {
	float start_colors[ZONE_N];
	int duration_ms;
};

typedef std::array<unsigned char,3> color;
typedef std::vector<color> palette;
typedef std::vector<animation_step> animation;

std::vector<animation> animations;
std::vector<palette> palettes;
timeval step_start;
timeval current_time;

int anim = 0;
int pal = 0;
int anim_step = 0;
unsigned char brightness = 255;
float speed = 1.0f;


void close_zone_fd() {
	for (int i = 0; i < ZONE_N; i++) 
		close(zone_fd[i]);
}


void cleanup() {
	if (fd) {
		close(fd);
		remove(path.c_str());
		close_zone_fd();
	}
}


void init_zone_fd() {
	for (int i = 0; i < ZONE_N; i++) {
		std::string p = zones_path + "zone0" + std::to_string(i);
		zone_fd[i] = open(p.c_str(), O_WRONLY);
		
		if (zone_fd[i] < 0) {
			std::cerr << "Couldn't open " << p << " (" << errno << ")\n";
			cleanup();
			exit(1);
		}
	}
}


void parse_colour(color* c, std::string s) {
	for (size_t i = 0; i < 3; i++) 
		(*c)[i] = (unsigned char) std::stoi(s.substr(2 * i, 2), nullptr, 16);
}


void init_anim() {
	std::string home = getenv("HOME");
	std::ifstream file;
	file.open(home + anim_path);
	
	if (!file) {
		std::cerr << "Couldn't open animation file\n";
		return;
	}
	
	animations.clear();
	
	std::string line;
	
	while (std::getline(file, line)) {
		std::string el;
		std::stringstream ss(line);
		animation_step step;
		
		if (line.length() == 0 || line[0] < '0' || line[0] > '9') {
			if (line.length() > 0 && line[0] == '[') 
				animations.push_back(animation());

			continue;
		} else if (animations.size() == 0) {
			std::cerr << "Apparent animation steps ignored (no preceding animation label): " << line << '\n';
			continue;
		}
		
		std::getline(ss, el, '\t');
		step.duration_ms = std::stoi(el);
		
		for (int i = 0; i < ZONE_N; i++) {
			std::getline(ss, el, '\t');
			step.start_colors[i] = std::stof(el);
		}
		
		animations.back().push_back(step);
	}
	
	file.close();
}


void init_palette() {
	std::string home = getenv("HOME");
	std::ifstream file;
	file.open(home + palette_path);
	
	if (!file) {
		std::cerr << "Couldn't open palette file\n";
		return;
	}
	
	palettes.clear();
	
	std::string line;
	
	while (std::getline(file, line)) {
		std::string el;
		std::stringstream ss(line);
		palette p;
		color c;
		
		if (line.length() == 0 || line[0] == '#') 
			continue;
		
		std::getline(ss, el, '\t');
		
		while (std::getline(ss, el, '\t')) {
			parse_colour(&c, el);
			p.push_back(c);
		}
		
		palettes.push_back(p);
	}
	
	file.close();
}


void term(int signum) {
	cleanup();
	exit(-1);
}


void set_rgb(int zone, char* colour) {
	write(zone_fd[zone], colour, 6);
}


// Reads instructions from controller
// 
// Possible instructions:
// Zzrrggbb - sets zone z to color hex #rrggbb
// Bx - sets brightness to x (0 - 255)
// Ax - plays animation x (uint)
// Px - set palette to x (uint)
// QSz - queries color of zone z; response: color
// QA - queries currently playing animation; response: int
// QP - queries currently used palette
// RA - reload animations
// RP - reload palette
// Sx - sets speed to x (0 - 255)
//
// Response is fed through separate response pipe [responses currently unsupported]
// Response data types:
// Crrggbb - color hex #rrggbb
// Sx - string "x"
// Ii - integer i
// Bb - boolean b (0 - 1)
// Ex - error string "x"

void read_pipe() {
	int n = read(fd, buffer, sizeof(buffer) - 1);
	
	if (n) {
		switch (buffer[0]) {
			case 'Z': {
				if (n < 8) {
					std::cerr << "Invalid command length " << n <<'\n';
					break;
				}
				
				anim = 0;
				int zone = buffer[1] - '0';
				
				if (zone < 0 || zone >= ZONE_N) {
					std::cerr << "Invalid zone: " << zone << '\n';
					break;
				}
				
				buffer[8] = 0;
				
				set_rgb(zone, &buffer[2]);
			} break;
			
			case 'A': {
				anim = std::atoi(&buffer[1]);
				
				if (anim < 0 || anim > animations.size()) {
					std::cerr << "Invalid animation: " << anim << '\n';
					anim = 0;
					break;
				} else if (animations[anim - 1].size() == 0) {
					std::cerr << "No steps in animation " << anim << '\n';
					anim = 0;
					break;
				}
				
				anim_step = 0;
				gettimeofday(&current_time, NULL);
				step_start = current_time;
			} break;

			case 'P': {
				pal = std::atoi(&buffer[1]);
				
				if (pal < 0 || pal > palettes.size()) {
					std::cerr << "Invalid palette: " << pal << '\n';
					pal = 0;
					break;
				} else if (palettes.size() > 0 && palettes[pal - 1].size() == 0) {
					std::cerr << "No colours in palette: " << pal << '\n';
					pal = 0;
					break;
				}
				
				anim_step = 0;
				gettimeofday(&current_time, NULL);
				step_start = current_time;
			} break;

			case 'R': {
				if (buffer[1] == 'A')
					init_anim();
				else if (buffer[1] == 'P')
					init_palette();
				else 
					std::cerr << "Invalid command: " << buffer << '\n';
				
				anim = 0;
				pal = 0;
			} break;
			
			case 'S': {
				speed = std::stof(&buffer[1]);
				anim_step = 0;
				gettimeofday(&current_time, NULL);
				step_start = current_time;
			} break;
			
			default:
			std::cerr << "Invalid command: " << buffer[0] << '\n';
		}
	}
}


int diff_usec(timeval* stop, timeval* start) {
	int secs = stop->tv_sec - start->tv_sec;
	int usecs = stop->tv_usec - start->tv_usec;
	return usecs + 1000000 * secs;
}


void set_msec(timeval* t, int msec) {
	t->tv_sec -= msec / 1000;
	int usecs = t->tv_usec - (msec % 1000) * 1000;

	if (usecs < 0) {
		usecs += 1000000;
		t->tv_sec -= 1;
	}
	
	t->tv_usec = usecs;
}


unsigned char hex(unsigned char x) {
	const char digits[17] = "0123456789abcdef";
	return digits[x & 0x0f];
}



void do_anim_step() {
	gettimeofday(&current_time, NULL);
	int dtime = (speed * diff_usec(&current_time, &step_start)) / 1000;
	int step_duration = animations[anim - 1][anim_step].duration_ms;
	
	// Advance to next animation step
	while (dtime >= step_duration) {
		step_start = current_time;
		set_msec(&step_start, (dtime - step_duration) / speed);
		dtime -= step_duration;
		anim_step++;
		
		if (anim_step >= animations[anim - 1].size())
			anim_step = 0;
		
		step_duration = animations[anim - 1][anim_step].duration_ms;
	}
	
	// Regularise animation step number
	if (anim_step >= animations[anim - 1].size())
		anim_step = 0;
	
	int next_step = anim_step + 1;
	
	if (next_step >= animations[anim - 1].size())
		next_step = 0;
	

	animation current_animation = animations[anim - 1];
	palette current_palette = palettes[pal - 1];
	size_t pal_size = current_palette.size();
	float step_frac = (float) dtime / (float) current_animation[anim_step].duration_ms;

	for (int zone = 0; zone < ZONE_N; zone++) {
		char colour_hex[6];
		
		float current = current_animation[anim_step].start_colors[zone];
		float next = current_animation[next_step].start_colors[zone];
		
		// Compute position in palette from interpolated steps
		float palette_colour = ((1 - step_frac) * current + step_frac * next) * pal_size;
		
		if (palette_colour >= pal_size)
			palette_colour = fmod(palette_colour, pal_size);
		else if (palette_colour < 0)
			palette_colour = 0;
		
		int prev_colour = palette_colour;
		int next_colour = palette_colour + 1;
		float r = palette_colour - prev_colour;
		
		if (next_colour >= pal_size)
			next_colour %= pal_size;
		
		for (int i = 0; i < 3; i++) {
			// Interpolate palette colours
			int colour = (1 - r) * current_palette[prev_colour][i] + r * current_palette[next_colour][i];
			
			colour_hex[2 * i] = hex(colour >> 4);
			colour_hex[2 * i + 1] = hex(colour);
		}
		
		set_rgb(zone, colour_hex);
	}
}



int main() {
	signal(SIGINT, term);

	int uid = getuid();
	int err;
	path = "/run/user/" + std::to_string(uid) + "/omenrgb.pipe";
	
	init_zone_fd();
	init_palette();
	init_anim();
	
	if (err = mkfifo(path.c_str(), 0600)) {
		if (err == -1) {
			std::cerr << "Old pipe file was present and automatically removed.\n";
			remove(path.c_str());
		} else {
			std::cerr << "Failed to open pipe. (" << err << ")\n";
			return err;
		}
	}
	
	fd = open(path.c_str(), O_RDONLY | O_NONBLOCK);
	
	if (fd < 0) {
		std::cerr << "Could not open pipe. (" << errno << ")\n";
		remove(path.c_str());
		return err;
	}
	
	while (true) {
		read_pipe();
		
		if (pal > palettes.size())
			pal = 0;
		
		if (anim > animations.size())
			anim = 0;
		else if (anim && pal) {
			do_anim_step();
			
			usleep(16000);	// = 0.016 s
		} else {
			usleep(200000);	// = 0.2 s
		}
	}
	
	cleanup();

	return 0;
}
