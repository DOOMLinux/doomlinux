all: minimaliso

minimaliso:
	wget https://buildroot.org/downloads/buildroot-2023.02.1.tar.gz
	tar xzvf buildroot-2023.02.1.tar.gz 
	cd buildroot-2023.02.1 && make menuconfig
	cd buildroot-2023.02.1 && make -j$(nproc)