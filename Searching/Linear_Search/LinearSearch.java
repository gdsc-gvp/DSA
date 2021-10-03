import java.util.Scanner;

public class LinearSearch {

    public static void main(String[] args) {

        int n;  //number of elements in array

        Scanner s = new Scanner(System.in) ;

        n = s.nextInt(); 

        int[] arr = new int[n] ; //declaration of array
        int target; //element which we want to find 

        //Enter elements in array
        for(int i = 0; i < n; i++)
        {
            arr[i] = s.nextInt();
        }
        
        target = s.nextInt();//Enter the element you want to find 
        int ans = linearSearch(arr, target); // returns the index of target element
        System.out.println(ans) ;
    }

    // search in the array: return the index if element found otherwise return -1
   public static int linearSearch(int[] arr, int target) {
        if (arr.length == 0) {
            return -1;
        }

        // run a for loop
        for (int index = 0; index < arr.length; index++) {
            // check for element at every index if it is = target
            if (arr[index] == target) {
                return index;
            }
        }
        // this line will execute if none of the return statements above have executed
        // hence the target not found
        return -1;
    }


}