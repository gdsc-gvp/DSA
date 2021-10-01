#include <stdio.h>

//Function For Merging
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid) //Its copying all the remaining elements from A to B 
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high) //Its copying all the remaining elements from B to C 
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++) //Copying elements back to A from B
    {
        A[i] = B[i];
    }
    
}
//this function divides the array into two parts, Then, it recursively calls itself passing these  divided subarrays
void mergeSort(int A[], int low, int high){ 
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high); //This will merge the resultant sorted subarrays
    }
}

int main()
{
    int n; //Number of elements in array
    scanf("%d",&n);
    int arr[n] ; 
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr, 0, n);
    //Print the result
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
