//fibnocci search

#include<iostream>
using namespace std;

int main()
{
    int a[100],n,i,s,c=0,l;
    int fibm=1,m1=0,m2=1,offset=0;
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"enter the elements : "<<endl;
    for(i=0;i<n;i++)
     cin>>a[i];
     cout<<"Enter the search element : ";
     cin>>s;
     while(fibm<n)
     {
         m2=m1;
         m1=fibm;
         fibm=m1+m2;
         
     }
     while(c<=n+1)
     {
         l=offset+m2;
         i=(n>l)?l:n;
         if(a[i]==s)
         {
             cout<<"Element found at "<<i+1<<" position ";
             i=-1;
             break;
         }

         else if (a[i]>s)
         {
             fibm=m2;
             m1=m1-m2;
             m2=fibm-m1;
             c++;
         }
         else{

             fibm=m1;
             m1=m2;
             m2=fibm-m1;
             offset=i;
             c++;
         }
     }

     if(a[0]==s)
     cout<<"Element found at 1 position "<<endl;
     if(i!=-1)
     cout<<"Element is not found in the array";
}
