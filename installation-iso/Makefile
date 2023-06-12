all: minimal.iso

minimal.iso: mkiso

mkiso: 
	wget https://git.kernel.org/torvalds/t/linux-6.4-rc6.tar.gz
	tar xvzf linux-6.4-rc6.tar.gz
	cd linux-6.4-rc6 && make defconfig
	cd linux-6.4-rc6 && make -j$(nproc)
	wget https://busybox.net/downloads/busybox-1.35.0.tar.bz2
	tar -xf busybox-1.35.0.tar.bz2
	cd busybox-1.35.0 && make defconfig
	cd busybox-1.35.0 && CONFIG_STATIC=y && make -j$(nproc)