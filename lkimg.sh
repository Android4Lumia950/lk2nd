#!/bin/bash
#cleanup
rm -rf lk.img build-lk2nd-msm8994/m/
make ARCH=arm -j12 TOOLCHAIN_PREFIX=arm-none-eabi- lk2nd-msm8994 LK2ND_BUNDLE_DTB=msm8992-msft-talkman.dtb USE+TARGET_DISPLAY=true
sudo dd if=/dev/zero of=build-lk2nd-msm8994/lk.img bs=1 count=1M
sudo mkfs.vfat build-lk2nd-msm8994/lk.img
mkdir build-lk2nd-msm8994/m
sudo mount build-lk2nd-msm8994/lk.img build-lk2nd-msm8994/m
sudo cp build-lk2nd-msm8994/emmc_appsboot.mbn build-lk2nd-msm8994/m/
sudo umount build-lk2nd-msm8994/m
