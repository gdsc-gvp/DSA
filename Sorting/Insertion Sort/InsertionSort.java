import java.util.Arrays;
import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Enter the size of the array : ");
        n= sc.nextInt();//n is for the size of the array.

        int[] arr = new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter the "+(i+1)+" element in the array : ");
            arr[i]=sc.nextInt();//reading elements of the array from the user.
        }
        insertionsort(arr,n);
        System.out.println(Arrays.toString(arr));

    }

    public static void insertionsort(int[] arr, int n) {
        for(int i=0;i<n-1;i++)
        {
            for(int j=1+i;j>0;j--)
            {
                if(arr[j]<arr[j-1])
                {
                    int temp; //swapping
                    temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                }
                else
                {
                    break;
                }
            }
        }
    }
}