#!/bin/bash
#cleanup
rm -rf lk.img build-lk1st-msm8994/m/
rm -rf lk.img build-lk1st-msm8992/m/
head_rev=$(git rev-parse --short HEAD)
head_date=$(git log -1 --format=%cd --date=format:"%Y%m%d")
echo "Which device are you using?"
echo "1) Lumia 950(msm8992)"
echo "2) Lumia 950 XL(msm8994)"
read -p "Enter the number of your choice: " choice
if [ "$choice" -eq 1 ]; then
    make ARCH=arm TOOLCHAIN_PREFIX=arm-none-eabi- lk1st-msm8992 DEBUG=1 LK2ND_VERSION=lk2nd-msm8992-lumia-$head_rev-$head_date LK2ND_BUNDLE_DTB=msm8992-msft-talkman.dtb
sudo dd if=/dev/zero of=build-lk1st-msm8992/lk.img bs=1 count=1M
sudo mkfs.vfat build-lk1st-msm8992/lk.img
mkdir build-lk1st-msm8992/m
sudo mount build-lk1st-msm8992/lk.img build-lk1st-msm8992/m
sudo cp build-lk1st-msm8992/emmc_appsboot.mbn build-lk1st-msm8992/m/
sudo umount build-lk1st-msm8992/m
elif [ "$choice" -eq 2 ]; then
    make ARCH=arm TOOLCHAIN_PREFIX=arm-none-eabi- lk1st-msm8994 DEBUG=0 LK2ND_VERSION=lk2nd-msm8994-lumia-$head_rev-$head_date LK2ND_BUNDLE_DTB=msm8994-msft-cityman.dtb
sudo dd if=/dev/zero of=build-lk1st-msm8994/lk.img bs=1 count=1M
sudo mkfs.vfat build-lk1st-msm8994/lk.img
mkdir build-lk1st-msm8994/m
sudo mount build-lk1st-msm8994/lk.img build-lk1st-msm8994/m
sudo cp build-lk1st-msm8994/emmc_appsboot.mbn build-lk1st-msm8994/m/
sudo umount build-lk1st-msm8994/m
else
    echo "Invalid choice. Please enter 1 or 2."
fi
