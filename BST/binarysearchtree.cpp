#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *start = NULL;
int insert(int data);
void preorder(struct node *temp);
void inorder(struct node *temp);
void postorder(struct node *temp);
int search(int data);
int deletion(int data);
int main(){
    int data,i,n,c=-1,r;
    cout<<"enter the no. of elements"<<endl;
    cin>>n;
    cout<<"enter the elements"<<endl;
    for(i=0;i<n;i++){
    cin>>data;
    insert(data);
    }
    while(c!=0){
        cout<<"0.Exit\n1.Inserting\n2.Searching\n3.Deleting\n4.Display\nenter your choice"<<endl;
        cin>>c;
            if(c==1){
            cout<<"enter the data"<<endl;
            cin>>data;
            insert(data);
            }
            else if(c==2){
            cout<<"enter the search element :"<<endl;
            cin>>data;
            r=search(data);
            if(r==-1)
            cout<<"search element "<<data<<" is not in the tree"<<endl;
            else
            cout<<"search element "<<data<<" is present in the tree at a depth of "<<r<<endl;
            }
            else if(c==3){
            cout<<"enter the element you want to delete :"<<endl;
            cin>>data;
            r=deletion(data);
            if(r==-1)
            cout<<"element "<<data<<" is not in the tree"<<endl;
            else
            cout<<"element "<<data<<" is Deleted"<<endl;
            }
            else if(c==4)
        {
            cout<<"Pre order : ";
                    preorder(start);
                    cout<<endl;
                    cout<<"Post order : ";
                    postorder(start);
                    cout<<endl;
                    cout<<"In order : ";
                    inorder(start);
                    cout<<endl;
        }
        else if(c!=0)
        cout<<"enter correct input"<<endl;
        
    }
    free(start);
    return 0;
    
}
int insert(int data)
{
  struct node *temp,*t;
  t = (struct node*)malloc(sizeof(struct node));
  t->data = data;
  t->right = NULL;
  t->left = NULL;
  if(start == NULL)
  {
      start=t;
      return 0;
  }
  temp = start;
  for(;;){
      if(t->data<temp->data)
      {
        if(temp->left == NULL)
        {
           temp->left = t;
           return 0 ;
        }
        else
        {
           temp = temp->left;  
        }
      }
      else
      {
        if(temp->right == NULL)
        {
           temp->right = t; 
           return 0;
        }
        else
        {
           temp = temp->right;  
        }  
      }
  }
}
void preorder(struct node *temp)
{
    cout<<temp->data<<" ";
    if(temp->left!=NULL)
    preorder(temp->left);
    if(temp->right!=NULL)
    preorder(temp->right);
}
void inorder(struct node *temp)
{
    if(temp->left!=NULL)
    inorder(temp->left);
    cout<<temp->data<<" ";
    if(temp->right!=NULL)
    inorder(temp->right);
}
void postorder(struct node *temp)
{
    if(temp->left!=NULL)
    postorder(temp->left);
    if(temp->right!=NULL)
    postorder(temp->right);
    cout<<temp->data<<" ";
}
int search(int data){
  int d=0;
  struct node *temp;
  temp = start;
  for(;;)
  {   
    if(data>temp->data)
    {
     if(temp->right==NULL&&temp->left==NULL)
     return -1;
     else
     temp = temp->right;
     d++;
    }
    else  if(data<temp->data)
    {
     if(temp->right==NULL&&temp->left==NULL)
     return -1;
     else
     temp = temp->left;
     d++;
    }
    else if(data==temp->data)
     return d;
    else
     return -1;
  }
}
int deletion(int data)
{
    struct node *temp,*t;
    int s;
    temp = start;
    if(start==NULL)
    {
        cout<<"Tree is empty"<<endl;
        return 0;
    }
    for(;;)
    {
        if(data>temp->data){
         if(temp->right==NULL&&temp->left==NULL)
         return -1;
         else {   
         t = temp;     
         temp = temp->right;}
        }
        else if(data<temp->data){
          if(temp->right==NULL&&temp->left==NULL)
          return -1;
          else{
           t = temp;   
          temp = temp->left;}
        }
        else if(data==temp->data)
        {
            //-----
            if(temp->left==NULL && temp->right==NULL){
                if(data>t->data)
                t->right = NULL;
                else
                t->left = NULL;
            }
            //.----
            else if(temp->left==NULL || temp->right==NULL)
            {
                if(temp->left==NULL){
                if(data>t->data)
                t->right = temp->right;
                else
                t->left = temp->right;
                }
               else{
                if(data>t->data)
                t->right = temp->left;
                else
                t->left = temp->left;
                }
            }
            //..---
            else
            {
             s = temp->left->data;
             cout<<s<<endl;
             deletion(s);
             temp->data = s;
            }
            return 0;
        }
        else
          return -1;
        
    }
}
