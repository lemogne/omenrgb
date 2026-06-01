// Library to interact with OMEN keyboard lights
// Author: legemorog
// Anno 2026

#include <fstream>
#include <string>
#include <unistd.h>

namespace omenlib {
	std::ofstream daemon_fd;
	std::string path;


	void init() {
		int uid = getuid();
		path = "/run/user/" + std::to_string(uid) + "/omenrgb.pipe";
		daemon_fd.open(path.c_str());
	}


	void set_color(size_t zone, std::string color) {
		daemon_fd << 'Z' << zone << color << '\n' << std::flush;
	}


	void set_palette(size_t n) {
		daemon_fd << 'P' << n << '\n' << std::flush;
	}


	void set_animation(size_t n) {
		daemon_fd << 'A' << n << '\n' << std::flush;
	}


	void set_speed(float s) {
		daemon_fd << 'S' << s << '\n' << std::flush;
	}


	void set_brightness(float b) {
		daemon_fd << 'B' << b << '\n' << std::flush;
	}


	void reload_palettes() {
		daemon_fd << "RP" << '\n' << std::flush;
	}


	void reload_animations() {
		daemon_fd << "RA" << '\n' << std::flush;
	}


	void deinit() {
		daemon_fd.close();
	}
};
