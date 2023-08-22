// UEFI From Scratch - ThatOSDev ( 2021 - 2022 )
// https://github.com/ThatOSDev/C_UEFI

#include <stdint.h>
#include "efi.h"
#include "efihelpers.h"

extern int GetInt();

int main() { }

// This is like int main() in a typical C program.
// In this case, we create an ImageHandle for the overall EFI interface,
// as well as a System Table pointer to the EFI_SYSTEM_TABLE struct.
// UEFI 2.9 Specs PDF Page 91
EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    efi_clear(SystemTable);

    efi_print(SystemTable, L"Welcome to ");

    efi_cprint(SystemTable, L"DivinityC ", EFI_YELLOW);

    efi_set_color(SystemTable, EFI_LIGHTGRAY);

    efi_print(SystemTable, L"EFI\r\n");

    
    int x = GetInt();
    if(x == 5)
    {
        efi_print(SystemTable, L"IT WORKS OMG\r\n");
    }
    //char c = x + '0';
    //SystemTable->ConOut->OutputString(SystemTable->ConOut, &c);

    efi_cprint(SystemTable, L"\nHit any key...\r\n", EFI_LIGHTGREEN);

    // This clears the keyboard buffer.    
    SystemTable->ConIn->Reset(SystemTable->ConIn, 1);

    // We setup the struct to take keyboard input.
    EFI_INPUT_KEY Key;

    // In a while loop to see if the keyboard has a key stroke in the buffer.
    while((SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key)) == EFI_NOT_READY);

    // The EFI needs to have a 0 ( or EFI_SUCCESS ) in order to know everything is ok.
    return 0;
}
