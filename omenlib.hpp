void init();	// Initialises OMENlib
void set_color(size_t zone, std::string color);	// Set colour in zone to hex value
void set_palette(size_t n);	// Set palette (1-indexed)
void set_animation(size_t n);	// Set animation (1-indexed)
void set_speed(float s);	// Set animation speed (1.0 is normal)
void set_brightness(float b);	// Set brightness (1.0 is full)
void reload_palettes();	// Reloads palettes from file
void reload_animations();	// Reloads animations from file
void deinit();	// Deinitialises OMENlib
