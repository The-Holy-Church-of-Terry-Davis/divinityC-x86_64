cd ./Boot
echo "Compiling to *.o"
gcc -Wall -Werror -m64 -ffreestanding -c ../efimain.c -o efimain.o
echo "Compiling to BOOTX64.EFI"
gcc -Wall -Werror -m64 efimain.o -nostdlib -shared -Wl,-shared -e efi_main -o BOOTX64.EFI

echo "Removing *.o files"
rm -f *.o

echo "All done, BOOTx64.EFI is in ./Boot"
