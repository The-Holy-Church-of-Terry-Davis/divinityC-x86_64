namespace EfiNet.Types;

public class SafeList<T> where T: unmanaged
{
    private NativeList native { get; set; }
    public int length => native.length;

    public unsafe T? this[int index]
    {
        get {
            T* ptr = (T*)(native.ptr);
            
            if(index >= length)
            {
                return null;
            }

            return ptr[index];
        }
    }

    public SafeList(NativeList native)
    {
        this.native = native;
    }
}