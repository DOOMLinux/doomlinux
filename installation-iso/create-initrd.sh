#!/bin/bash

#Creating the initrd directory
mkdir initrd
cd initrd

#Creating the bin dev proc and sys directories
mkdir -p bin dev proc sys
cd bin

#Copying the busybox generated with make under the bin directory
cp ./busybox-1.35.0/busybox ./ 

#Iterating through the list of commands in busybox and creating #symbolic links for each of the commands, which will imitate the real
#functionality
for alpha in $(./busybox --list); do
 	ln -s /bin/busybox ./$alpha
done

#Creating the init file which will be mounting the root file system
echo '#!/bin/sh' > init
echo 'mount -t sysfs sysfs /sys' >> init
echo 'mount -t proc proc /proc' >> init
echo 'mount -t devtmpfs udev /dev' >> init
echo 'sysctl -w kernel.printk="2 4 1 7"' >> init
echo '/bin/sh' >> init
echo 'poweroff -f' >> init

 
chmod -R 777 .
 
#Creating the initrd.img 
find . | cpio -o -H newc > ../initrd.img

#Exiting the directory
cd ..