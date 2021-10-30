public class StackArrayapp {

    public static void main(String[] args) {
       
        StackArray sa=new StackArray(6);
        sa.push(7);
        sa.push(6);
        sa.push(8);
        sa.push(9);
        sa.push(3);
        sa.push(2);
        sa.display();
        sa.push(1);
        try{
        int k=sa.peek();
         System.out.println("peek " +k);
            System.out.println("popped an item "+sa.pop());
            System.out.println("popped an item "+sa.pop());
        }catch (Exception e){
            
        }
        sa.display();
       
    }
    
}

class StackArray {
 private int maxSize; //size of stack array
 private int[] stackData;
 private int top; //top of stack
//-------------------------------------------------------------------------
 public StackArray(int s) {
     this.stackData=new int[s];
     this.maxSize=s;
     this.top=-1;
 }
 public boolean isEmpty() {
     return top==-1;
 }
 public boolean isFull() {
    return top==maxSize-1;
 }
 public void push(int item) {//before inserting check whether the array is full
     //top++;
     //stackData[top]=item;
     if(isFull()){
         System.out.println("Stack is full");
         return;
     }
     stackData[++top]=item;
     
 }
 public int pop() throws Exception {
     /*int temp=stackData[top];
     top--;
     return temp;*/
     if(isEmpty()){
         throw new Exception("Stack is empty cannot pop");
     }
     
     return stackData[top--];
 }
 public int peek() throws Exception {
     
     if(isEmpty()){
         throw new Exception("Stack is empty cannot give the peek");
     }
     
     return stackData[top];
 }
 public void display() {
     System.out.println("Start printing stack data");
     for(int i=top; i>=0; i--){
         System.out.println(stackData[i]);
     }
     System.out.println();
 }
} //end class StackArray
