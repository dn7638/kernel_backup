#!/bin/bash

sudo insmod pxt4.ko
sudo mount -t pxt4 /dev/sdb /mnt/test
cd ..
sudo fio rand-write.fio
sudo umount /mnt/test
sudo rmmod pxt4
cd pxt4
dmesg
