#!/usr/bin/bash

if [ "$EUID" -ne 0 ]; then
  echo "This script must be run with superuser privileges. Exiting."
  exit 1
fi

# Create a 40MB VHDX file
dd if=/dev/zero of=drive.vhdx bs=1M count=40

# Format the VHDX file with GPT partition table
parted drive.vhdx mklabel gpt

# Create a FAT32 partition
parted drive.vhdx mkpart primary fat32 1MiB 100%

# Format the partition as FAT32
mkfs.fat -F32 drive.vhdx

# Mount the VHDX file
mkdir mountpoint
sudo mount -o loop drive.vhdx mountpoint

# Create the EFI/Boot directory
mkdir -p mountpoint/EFI/Boot

# Move the BOOTX64.EFI file to EFI/Boot directory
sudo cp ../EFI/Boot/BOOTX64.EFI mountpoint/EFI/Boot/BOOTX64.EFI

# Unmount the VHDX file
# sudo umount mountpoint
# rm -rf mountpoint