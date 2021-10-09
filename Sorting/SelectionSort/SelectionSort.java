import java.util.Arrays;
import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,temp1,temp2;
        System.out.print("Enter the size of the array : ");
        n= sc.nextInt();
        temp1=n;
        temp2=n;
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter the "+(i+1)+" element of the array : ");
            arr[i]=sc.nextInt();
        }
        for(int i=0;i<n-1;i++)
        {
            swap(arr,findHighInd(arr,--temp1),--temp2);
        }
        System.out.println(Arrays.toString(arr));

    }
    public static int findHighInd(int[] arr,int out)
    {
        int temp=arr[0],hig_ind=0;
        for(int i=0;i<=out;i++)
        {
            if(temp<arr[i])
            {
                temp=arr[i];
                hig_ind=i;
            }
        }
        return hig_ind;
    }
    public static void swap(int[] arr,int num1,int num2)
    {
        int temp;
        temp=arr[num1];
        arr[num1]=arr[num2];
        arr[num2]=temp;
    }
}
