echo "Compiling EFI"
./EFI/compileEFI.sh
echo "Compiled"
echo "Mounting drive.hdd"
./EFI/mountDrive.sh
echo "Mounted"
echo "Moving files to drive.hdd"
sudo mv ./EFI/BOOTX64.EFI /mnt/G/EFI/Boot