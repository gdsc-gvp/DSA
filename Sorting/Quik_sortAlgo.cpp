#include<bits/stdc++.h>
using namespace std;
#define int long long
//used for 64 bit integers


int partition(int a[],int l,int r){
   int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}


void quicksort(int a[],int l,int r){
    if(l<r){
        int pi=partition(a,l,r);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,r);
    }
}



//main function should always be a 32 bit one so we use int32_t
int32_t main(){
int n;
cin>>n;
//size of the array
int a[n];
//declaring an array of size n
for(int i=0;i<n;i++){
    cin>>a[i];
}
quicksort(a,0,n-1);
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
}


Now,lets discuss about its time complexity
In best case(when the pivot is at mid of the considered sub array) its time complexity would be O(nlog(n))
  in worst case(when the pivot is at start or end of the considered sub array) its time complexity would be O(n^2)
