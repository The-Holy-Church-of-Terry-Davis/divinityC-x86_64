#include<efi.h>

#ifndef NET_INTEROP_H
#define NET_INTEROP_H

typedef void *(AllocPtr)(int);

/*
    arg1 = Function pointer to whatever our equivelant of "malloc" is!
*/
extern void InitializeInterop(AllocPtr alloc);

#ifndef CS_KERNEL
#define CS_KERNEL

typedef struct
{
    EFI_SYSTEM_TABLE *sysTable;             //I will have to port the entirety of the UEFI runtime to C#... goodluck future me!
} Kernel;

#endif

typedef struct
{
    void *ptr;
    int length;
    NativeType tp;                          //Only native types will be supported!!!
} NativeList;

typedef enum
{
    INT,
    CHAR,
    LONG
} NativeType;

typedef struct
{
    void *ptr;
    int length;
} GenericList;

typedef struct
{
    char *ptr;
    int length;
} SafeString;

#endif