import java.util.Arrays;
import java.util.Scanner;

public class BubbleSort{
    public static void main(String[] args){
        int n;  //number of elements in array
        Scanner s = new Scanner(System.in) ;

        n = s.nextInt(); 

        int[] arr = new int[n] ; //declaration of array
        
        //Enter elements in array
        for(int i = 0; i < n; i++)
        {
            arr[i] = s.nextInt();
        }
        bubbleSort(arr); //This function will sort the array
        System.out.println(Arrays.toString(arr));
    }
    public static void bubbleSort(int[] arr){
        boolean swapped;
        //Run the steps n-1 times
        for (int i = 0; i < arr.length; i++) {
            swapped  = false;
        //For each step max item will come at the last respective index
            for (int j = 1; j < arr.length-i; j++) {
            //swap if the item is smaller than the previous one
                if(arr[j] < arr[j-1]){
                //swap
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    swapped = true;
                }
            }
            //If you did not swap for a particular value of i, it means array is sorted hence stop the program
            if(!swapped){
                break;
            }
        }
    }
}