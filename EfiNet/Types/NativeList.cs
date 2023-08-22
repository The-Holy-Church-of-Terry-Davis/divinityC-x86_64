using System.Runtime.InteropServices;

namespace EfiNet.Types;

[StructLayout(LayoutKind.Sequential)]
public unsafe struct NativeList
{
    public void *ptr { get; set; }
    public int length { get; set; }

    public SafeList<T> ToSafe<T>() where T: unmanaged
    {
        return new SafeList<T>(this);
    }
}