#include<stdio.h>
#include<stdlib.h>
#define N 5

int stack[N];//Array implementation of stack
int top = -1, count = 0;

int isFull()
{
    return top==N-1;//If top is pointing to the last index array is full consequently stack is full
}

int isEmpty()
{
    return top==-1;//If top is pointing to the no index array is empty consequently stack is empty
}
//Function to push an element into the stack
void push(int a)
{
  //Check whether stack is full or not
    if(isFull())
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        top = top+1;
        stack[top] = a;
        printf("%d pushed into stack\n",a);
    }
}
//Function to delete an element
void pop()
{
  //Check whether stack is empty or not
    if(isEmpty())
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d is popped from the stack\n",stack[top]);
        top = top-1;
    }
}
//Function to print the top element of the stack
void peek()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    printf("%d\n",stack[top]);
}

void main()
{
    isEmpty();
    push(4);
    push(2);
    push(3);
    push(1);
    push(6);
    push(7);
    peek();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
}
