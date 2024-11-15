# OMEN RGB

A simple application for setting keyboard backlight colours on OMEN laptops for Linux.

## Installation
*(Word of caution: this will require installing a [kernel module from GitHub]((https://github.com/pelrun/hp-omen-linux-module)). Its author has stated that it **may potentially damage your device**. Though I can state that it works on my machine^(TM), usage is still at your own risk. It may remap some keys as well, so if you've bound anything to your OMEN key for instance, you may have to remap it.)*
To install,
```sh
$ chmod +x ./install.sh
# ./install.sh
```
Installing will require root permission in places, so run with `sudo`/`doas`.

To build, 
```sh
$ chmod +x ./build.sh
$ ./build.sh
```

## Dependencies
Requires wxWidgets to build/install.
On Arch-based systems: 
`# pacman -S wxwidgets`
Debian-based:
`# pacman -S libwxgtk3.0-dev`
Others: Check if your package manager has the wxWidgets package or alternatively, [build it yourself](https://github.com/wxWidgets/wxWidgets).

The install script additionally installs the [`hp-omen-linux-module`](https://github.com/pelrun/hp-omen-linux-module), which you have to install manually if you are just using the build script. 

## Code
Written in fairly normal C++; should be compilable with any compiler from the past 20 years. 
The build/install scripts use `g++` by default; modify `build.sh` to change this behaviour.

## Future development
I may add a taskbar icon in the future.