//reversing linked list
#include<iostream>

using namespace std;
//Node in linkedlist
struct node
{
    int data;
    node* next;
};

class linkedlist
{
    public:
    node* head;
    linkedlist(){head=NULL;}

    void insert(int x)
    {
        node* newnode = new node;
        newnode->data = x;
        newnode->next = head;
        head = newnode;
    }

    void print()
    {
        node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
//Reversing linkedlist using 3-pointer method
    void reverse()
    {
        node* prev = NULL;
        node* curr = head;
        node* next = head;
        while(next!=NULL)
        {
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

};

int main()
{
    /* Start with the empty list */
    linkedlist ll;
    int n;
    cout<<"Enter the total count of elements ";
    cin>>n;
    cout<<"Enter the elements to be inserted "<<endl;
    int x;
    while(n--)
    {
      cin>>x;
      ll.insert(x);
    }
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();


    return 0;
}
