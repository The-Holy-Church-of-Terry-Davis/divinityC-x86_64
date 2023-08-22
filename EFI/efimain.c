// UEFI From Scratch - ThatOSDev ( 2021 - 2022 )
// https://github.com/ThatOSDev/C_UEFI

#define UNICODE

#include <stdint.h>
#include <wchar.h>  // Include this header for wide character strings

// These are the same typedefs used in the official PDF specs
typedef uint_least16_t      CHAR16;

typedef unsigned int        UINT32;
typedef unsigned long long  UINT64;

typedef unsigned char       BOOLEAN;

typedef void                *EFI_HANDLE;
typedef UINT64              EFI_STATUS;

// This struct is a placeholder and not usable at this time
// The code will not compile without it though.
typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

// We are forward declaring this struct so that the two function typedefs can operate.
struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// This function resets the string output.
typedef EFI_STATUS (*EFI_TEXT_RESET)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, BOOLEAN ExtendedVerification);

// This function prints the string output to the screen.
typedef EFI_STATUS (*EFI_TEXT_STRING)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);

// The struct for the EFI Text Output protocols.
// UEFI 2.9 Specs PDF Page 449
typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    EFI_TEXT_RESET      Reset;
    EFI_TEXT_STRING     OutputString;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// This is the main EFI header for all of the EFI.
// UEFI 2.9 Specs PDF Page 93
typedef struct EFI_TABLE_HEADER
{
    UINT64    Signature;
    UINT32    Revision;
    UINT32    HeaderSize;
    UINT32    CRC32;
    UINT32    Reserved;
} EFI_TABLE_HEADER;

// EFI has a system and runtime. This system table is the first struct
// called from the main section.
// UEFI 2.9 Specs PDF Page 94
typedef struct EFI_SYSTEM_TABLE
{
    EFI_TABLE_HEADER                hrd;
    CHAR16                          *FirmwareVendor;
    UINT32                          FirmwareVersion;
    EFI_HANDLE                      ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL  *ConIn;
    EFI_HANDLE                      ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
} EFI_SYSTEM_TABLE ;

// This is like int main() in a typical C program.
// In this case, we create an ImageHandle for the overall EFI interface,
// as well as a System Table pointer to the EFI_SYSTEM_TABLE struct.
// UEFI 2.9 Specs PDF Page 91
EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    // This clears the screen and buffer.
    SystemTable->ConOut->Reset(SystemTable->ConOut, 1);

    // Store the string in a CHAR16* variable using explicit type casting
    CHAR16 *message = (CHAR16 *)L"Working\r\n";

    // This prints the message to the screen
    SystemTable->ConOut->OutputString(SystemTable->ConOut, message);

    // We use this while loop to hang. At this point, simply shut off the computer.
    while (1) {};

    // The EFI needs to have a 0 (or EFI_SUCCESS) in order to know everything is okay.
    return 0;
}
