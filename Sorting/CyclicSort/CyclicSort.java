import java.util.Arrays;
import java.util.Scanner;

public class CyclicSort { /**cyclic sort varies with the given range of numbers in the
 array this algorithm is for [0 , N-1] and the size of array is 'N' **/
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n;
    System.out.print("Enter the size of the array : ");
    n= sc.nextInt();//reading the size of the array
    int[] arr = new int[n];
    System.out.println("Note :: In cyclic sort the elements of the array are either from [0,n-1] or [1,n] where n is size of the array");
    for(int i=0;i<n;i++)
    {
        System.out.print("Enter the "+(i+1)+" element of the array : ");
        arr[i]=sc.nextInt();//reading the elements of the array
    }
    cyclicsort(arr,n);
    System.out.println(Arrays.toString(arr));
}

    public static void cyclicsort(int[] arr, int n) {
        int k=0,temp=0;
        while(k<n)
        {
            if(arr[k] == k)
            {
                k++;
            }
            else
            {
                temp=arr[k]; //swapping with the correct index
                arr[k]=arr[temp];
                arr[temp]=temp;
            }
        }
    }
}