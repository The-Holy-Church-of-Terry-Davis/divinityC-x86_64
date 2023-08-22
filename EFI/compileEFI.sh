gcc -Wall -Werror -m64 -ffreestanding -c efimain.c -o efimain.o
gcc -Wall -Werror -m64 efimain.o -nostdlib -shared -Wl,-shared -e efi_main -o BOOTX64.EFI

rm -f *.o
