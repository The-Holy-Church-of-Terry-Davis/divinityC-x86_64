#include <stdint.h>
#include "efi.h"


void efi_print(EFI_SYSTEM_TABLE *SystemTable, CHAR16 *String) {
    SystemTable->ConOut->OutputString(SystemTable->ConOut, String);
}

// SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_YELLOW);
void efi_cprint(EFI_SYSTEM_TABLE *SystemTable, CHAR16 *String, int Color) {
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, Color);
    efi_print(SystemTable, String);
}

void efi_set_color(EFI_SYSTEM_TABLE *SystemTable, int Color) {
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, Color);
}

void efi_clear(EFI_SYSTEM_TABLE *SystemTable) {
    SystemTable->ConOut->Reset(SystemTable->ConOut, 1);
}
