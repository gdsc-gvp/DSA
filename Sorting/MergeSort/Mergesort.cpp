#include<bits/stdc++.h>
using namespace std;
#define int long long
//used for 64 bit integers
void merge(int a[],int l, int mid,int r){
    int i=l,j=mid+1,k=0;
    int c[r-l+1];
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            c[k++]=a[i++];
        }
        else{
            c[k++]=a[j++];
        }
    }
    while(i<=mid){
        c[k++]=a[i++];
    }
    while(j<=r){
        c[k++]=a[j++];
    }
    j=l;
    for(int i=0;i<r-l+1;i++){
a[j++]=c[i];
    }
}

void mergesort(int a[],int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

//main function should always be a 32 bit one so we use int32_t
int32_t main(){
       int n;
   cin >> n;
   //size of the array
   int a[n];
   //declaring an array of size n
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   mergesort(a,0,n-1);
   for (int i = 0; i < n; i++)
   {
      cout << a[i]<<" ";
   }
}
