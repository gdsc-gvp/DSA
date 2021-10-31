package stackArrayapp;

import java.util.Scanner;

/**
 *
 * @author Yasmi Kumarasiri - Stack Implementation using arrays
 */
public class stackArrayapp {

  public static void main(String[] args) throws Exception {
    int ch = 0;
    Scanner sc = new Scanner(System.in);
    StackArray sa = new StackArray();
    System.out.println("Stack operations using array\n");

    while (ch != 5) {
      System.out.println("\nChose one from the below options...\n");
      System.out.println("\n1.Push\n2.Pop\n3.Show\n4.Get the peek value\n5.Exit");
      System.out.println("\n Enter your choice \n");
      ch = sc.nextInt();
      switch (ch) {
        case 1:
          {
            sa.push(sc);
            break;
          }
        case 2:
          {
            sa.pop();
            break;
          }
        case 3:
          {
            sa.display();
            break;
          }
        case 4:
          {
            sa.peek();
            break;
          }
        case 5:
          {
            System.exit(0);
            break;
          }
        default:
          {
            System.out.println("Please Enter a choice(1-5)");
          }
      }
    }
  }
}

class StackArray {

  int top;
  int maxsize = 10;
  int[] stackData = new int[maxsize];

  public boolean isEmpty() {
    return top == -1;
  }

  public boolean isFull() {
    return top == maxsize - 1;
  }

  StackArray() {
    top = -1;
  }

  public void push(Scanner sc) {
    if (isFull()) {
      System.out.println("Stack is full");
      return;
    }
    stackData[++top] = sc.nextInt();
  }

  public int pop() throws Exception {
    if (isEmpty()) {
      throw new Exception("Stack is empty cannot pop");
    }

    return stackData[top--];
  }

  public int peek() throws Exception {
    if (isEmpty()) {
      throw new Exception("Stack is empty cannot give the peek");
    }

    return stackData[top];
  }

  void display() {
    System.out.println("Printing stack elements .....");
    for (int i = top; i >= 0; i--) {
      System.out.println(stackData[i]);
    }
  }
}
