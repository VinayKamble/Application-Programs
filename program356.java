import java.util.*;

class StringX
{
    public String StrLower(String str)
    {
        char Arr[] = str.toCharArray();

        for(int iCnt = 0; iCnt < Arr.length; iCnt++)
        {
            if((Arr[iCnt] >= 'A') && (Arr[iCnt] <= 'Z'))
            {
                Arr[iCnt] = (char)(Arr[iCnt] + 32);
            }
        }

        String ret = new String(Arr);

        return ret;
    }
}

class program356
{
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter your name : ");
        String name = sobj.nextLine();

        StringX obj = new StringX();
        
        String sret = obj.StrLower(name);
        System.out.println("Converted string is : "+sret);
    }
}
