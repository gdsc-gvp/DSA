#include<stdio.h>
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            //Return the index of element if it is found
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    //If element not fiund Return -1
    return -1;
    
}
int main(){
    // Note: Sorted array is Required for binary search
    int size; //Size of the arry
    scanf("%d",&size);
    int arr[size] ;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int target; //Element which we want to find
    scanf("%d",&target);
    int ans = binarySearch(arr, size, target); //Will return the index of target element if found
    printf("%d",ans);
    return 0;
}