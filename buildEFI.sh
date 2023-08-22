#!/usr/bin/bash

if [ "$EUID" -ne 0 ]; then
  echo "This script must be run with superuser privileges. Exiting."
  exit 1
fi

echo "Attempting to update/install required packages"
sudo apt-get install -y qemu-utils qemu-system-x86 dotnet-sdk-7.0

chmod +x ./EFI/compileEFI.sh
chmod +x ./EFI/mountDrive.sh

echo "Compiling EFI"
sudo ./EFI/compileEFI.sh
echo "Compiled"

echo "Mounting drive.hdd"
sudo ./EFI/mountDrive.sh
echo "Mounted"

echo "Moving files to drive.hdd"
sudo mv ./EFI/BOOTX64.EFI /mnt/G/EFI/Boot