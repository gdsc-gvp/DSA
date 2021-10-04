//Implementation of Queue in C++ 
#include <iostream>
using namespace std;
int queue[1000];
int front = - 1,n=50; //assuming size of queue as 50
int rear = - 1;

void enqueue() {
   int val;
   if (rear == n - 1)
      cout<<"Queue Overflow"<<endl;
   else {
    
      front = 0;
      cout<<"Enter a value to be inserted : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}

void dequeue() {
   if (front == - 1) {
      cout<<"Queue Underflow ";
   return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;;
   }
}

void display() {
   if (front == - 1 )
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
         cout<<queue[i]<<" ";
      cout<<endl;
   }
}
void isempty()
{
    if(front==-1 && rear ==-1)
    {
        cout<<"Queue is empty"<<endl; 
    }
    else
    {
        cout<<"Queue is not empty"<<endl; 
    }
}
void peek()
{
    if(front==-1 && rear ==-1)
    {
        cout<<"Queue is empty"<<endl; 
    }
    else
    {
      cout<<"peek element of the queue is :"<<queue[front]<<endl; 
    }
}
int main() {
   int ch;
   cout<<"1) Insertion element to the queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) isempty"<<endl;
   cout<<"5) peek element"<<endl;
   cout<<"6) Exit"<<endl;
  while(1) {
   cout<<"Enter your choice : "<<endl;
   cin>>ch;
   switch (ch) {
      case 1: enqueue();
         break;
      case 2: dequeue();
         break;
      case 3:display();
         break;
      case 4: isempty();
         break;
      case 5: peek();
         break;
      case 6: exit(0);
         break;
      default: cout<<"Invalid choice"<<endl;
   }
  }
   return 0;
}
