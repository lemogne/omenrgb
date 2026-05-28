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
#include <iostream>

const int ZONE_N = 4;
char buffer[256] = {0};
int fd = 0;
std::string path;
std::string zones_path = "/sys/devices/platform/hp-wmi/rgb_zones/";
int zone_fd[ZONE_N];

typedef unsigned char color[3];

typedef std::vector<color> palette;

struct animation_step {
	float start_colors[ZONE_N];
	int duration_ms;
	bool is_interpolated;
};

typedef std::vector<animation_step> animation;

int anim = 0;
int pal = 0;
int anim_step = 0;
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
// Bx - sets brightness to x (0 - 100)
// Ax - plays animation x (uint)
// Px - set palette to x (uint)
// QSz - queries color of zone z; response: color
// QA - queries currently playing animation; response: int
// QP - queries currently used palette
// Sx - sets speed to x (0 - 100)
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
		else if (anim) {
			gettimeofday(&current_time, NULL);
			int dtime = diff_usec(&current_time, &step_start) / 1000;
			
			if (dtime > animations[anim][anim_step].duration_ms) {
				step_start = current_time;
				set_msec(&step_start, dtime - animations[anim][anim_step].duration_ms);
				anim_step++;
			}
			
			if (anim_step >= animations[anim].size()) {
				anim_step = 0;
			}
			
			bool interpolate = animations[anim][anim_step].is_interpolated;
			int next_step = anim_step + 1;
			
			if (next_step >= animations[anim].size())
				next_step = 0;
			
			for (int zone = 0; zone < ZONE_N; zone++) {
				char colour_hex[6];
				
				float current = animations[anim][anim_step].start_colors[zone];
				float next = animations[anim][next_step].start_colors[zone];
				
				float step_frac = (float) dtime / (float) animations[anim][anim_step].duration_ms;
				float palette_colour = ((1 - step_frac) * current + step_frac * next) * palettes[pal].size();
				
				int prev_colour = palette_colour;
				int next_colour = palette_colour + 1;
				
				if (next_colour >= palettes[pal].size())
					next_colour = 0;
				
				float r = palette_colour - prev_colour;
				
				for (int i = 0; i < 3; i++) {
					int colour = (1 - r) * palettes[pal][prev_colour][i] + r * palettes[pal][next_colour][i];
					
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
