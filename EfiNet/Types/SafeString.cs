using System.Runtime.InteropServices;

namespace EfiNet.Types;

[StructLayout(LayoutKind.Sequential)]
public unsafe struct SafeString
{
    public char *ptr;
    public int length;

    public static void CharPtrToSafe(char *ptr, int length, SafeString *ot)
    {
        *ot = new SafeString() { ptr = ptr, length = length };
    }

    public static char * SafeStrToUnsafe(SafeString *val)
    {
        return val->ptr;
    }
}