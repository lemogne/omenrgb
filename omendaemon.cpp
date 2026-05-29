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
std::string anim_path;
std::string palette_path;
int zone_fd[ZONE_N];

typedef std::array<unsigned char,3> color;

typedef std::vector<color> palette;

struct animation_step {
	float start_colors[ZONE_N];
	int duration_ms;
};

typedef std::vector<animation_step> animation;

int anim = 0;
int pal = 0;
int anim_step = 0;
unsigned char brightness = 255;
float speed = 1.0f;
std::vector<animation> animations;
std::vector<palette> palettes;

timeval step_start;
timeval current_time;


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
	file.open(home + "/.config/omenrgb/animations.cfg");
	
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
	file.open(home + "/.config/omenrgb/palettes.cfg");
	
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

void read_pipe(int signum) {
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
				}
				
				anim_step = 0;
				gettimeofday(&current_time, NULL);
				step_start = current_time;
			} break;

			case 'P': {
				pal = std::atoi(&buffer[1]);
				
				if (pal < 0 || pal > animations.size()) {
					std::cerr << "Invalid palette: " << pal << '\n';
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
	
	// Example of why exceptions are superior to error return values/types:
	fd = open(path.c_str(), O_RDONLY | O_NONBLOCK);
	
	if (fd < 0) {
		std::cerr << "Could not open pipe. (" << errno << ")\n";
		remove(path.c_str());
		return err;
	}
	
	while (true) {
		read_pipe(0);
		
		if (pal > palettes.size())
			pal = 0;
		
		if (anim > animations.size())
			anim = 0;
		else if (anim && pal) {
			gettimeofday(&current_time, NULL);
			int dtime = (speed * diff_usec(&current_time, &step_start)) / 1000;
			
			if (dtime > animations[anim - 1][anim_step].duration_ms) {
				step_start = current_time;
				set_msec(&step_start, (dtime - animations[anim - 1][anim_step].duration_ms) / speed);
				dtime -= animations[anim - 1][anim_step].duration_ms;
				anim_step++;
			}
			
			if (anim_step >= animations[anim - 1].size()) {
				anim_step = 0;
			}
			
			int next_step = anim_step + 1;
			
			if (next_step >= animations[anim - 1].size())
				next_step = 0;
			
			for (int zone = 0; zone < ZONE_N; zone++) {
				char colour_hex[6];
				
				float current = animations[anim - 1][anim_step].start_colors[zone];
				float next = animations[anim - 1][next_step].start_colors[zone];
				
				float step_frac = (float) dtime / (float) animations[anim - 1][anim_step].duration_ms;
				float palette_colour = ((1 - step_frac) * current + step_frac * next) * palettes[pal - 1].size();
				
				if (palette_colour >= palettes[pal - 1].size()) {
					palette_colour = fmod(palette_colour, palettes[pal - 1].size());
				}
				
				int prev_colour = palette_colour;
				int next_colour = palette_colour + 1;
				
				if (next_colour >= palettes[pal - 1].size())
					next_colour %= palettes[pal - 1].size();
				
				float r = palette_colour - prev_colour;
				
				for (int i = 0; i < 3; i++) {
					int colour = (1 - r) * palettes[pal - 1][prev_colour][i] + r * palettes[pal - 1][next_colour][i];
					
					colour_hex[2 * i] = hex(colour >> 4);
					colour_hex[2 * i + 1] = hex(colour);
				}
				
				set_rgb(zone, colour_hex);
			}
			
			usleep(16000);	// = 0.016 s
		} else {
			usleep(200000);	// = 0.2 s
		}
	}
	
	cleanup();

	return 0;
}
