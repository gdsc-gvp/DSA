// This program is to implement a queue.
// Given a list of numbers in a queue and removed the head of queue.


package Queue;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class QueueImp{
	public static void main(String[] args){
		Queue<Integer> queue = new LinkedList<>();
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter no. of elements you want to add in the queue: ");
		int n = sc.nextInt();

		for(int i = 0; i < n; i++){
			System.out.println("Enter " +(i+1)+ " element: ");
			int ele = sc.nextInt();
			queue.add(ele); 
		}

		System.out.println("Elements of queue: "+ queue);
  
        int removedele = queue.remove();
        System.out.println("Removed the head element: "+ removedele);
  
        System.out.println(queue);
  
        int head = queue.peek();
        System.out.println("New Head of the Queue: "+ head);
  
	}
}

// Output :

// Enter no. of elements you want to add in the queue: 
// 5
// Enter 1 element: 
// 23
// Enter 2 element: 
// 67
// Enter 3 element: 
// 43
// Enter 4 element: 
// 78
// Enter 5 element:
// 46
// Elements of queue: [23, 67, 43, 78, 46]
// Removed the head element: 23
// [67, 43, 78, 46]
// New Head of the Queue: 67