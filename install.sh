#!/bin/sh
set -e
if [ "$EUID" -ne 0 ]; then
	echo -e "\e[91m Error: need root to install. Use \e[92msudo/doas/su\e[91m to run this script.\e[0m"
	exit 1
fi

rules=n
if [ ! -f /sys/devices/platform/hp-wmi/rgb_zones/zone00 ]; then
	echo -e "\e[93mInstalling \e[92mhp-omen-linux-module\e[0m..."
	git clone https://github.com/pelrun/hp-omen-linux-module.git
	cd hp-omen-linux-module
	make
	cd ..
	rm -rf hp-omen-linux-module
	echo -e "\e[93mSuccessfully installed \e[92mhp-omen-linux-module\e[0m."
else
	echo -e "\e[92mhp-omen-linux-module\e[93m already installed.\e[0m"
	echo -e "\e[93mHave you set up rules in \e[92m/etc/udev/rules.d/\e[93m for user-space access to the kernel modules?\e[0m"
	printf "\e[93mThis means that you can write to \e[92m/sys/devices/platform/hp-wmi/rgb_zones/\e[93m without root permission [y/N]?\e[0m"
	read rules
fi

chmod a+rw /sys/devices/platform/hp-wmi/rgb_zones/*

if [ $rules != y ]; then
	echo -e "\e[93mCopying udev rules to allow non-root access to keyboard backlight kernel modules...\e[0m"
	echo -e "\e[93mIf there are permissions issues, modify \e[92m/etc/udev/rules.d/backlight.rules\e[93m to suit your configuration.\e[0m"
	echo -e "\e[93mIf you have installed \e[92mhp-omen-linux-module\e[93m and set up the proper udev rules for user access already under a different filename, you can remove one of the files.\e[0m"
	cp -t /etc/udev/rules.d/ backlight.rules
fi

echo -e "\e[93mBuilding \e[92omenrgb...\e[0m"
chmod +x build.sh
./build.sh
echo -e "\e[93mInstalling to \e[92m/usr/bin/\e[93m...\e[0m"
cp -t /usr/bin/ omenrgb
echo -e "\e[92mDone. Reboot for the changes to take effect.\e[0m"
