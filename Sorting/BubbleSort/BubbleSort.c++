#include <bits/stdc++.h>
using namespace std;
 
void bubbleSort(int arr[], int n)
{
    int temp;
    bool swapped;
    //Run the steps n-1 times
    for (int i = 0; i < n-1; i++)
    {
        swapped = false;
        for (int j = 0; j <n-1-i ; j++)
        {
            if(arr[j]>arr[j+1]){
            //Swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        } 
        //If you did not swap for a particular value of i, it means array is sorted hence stop the program
        if(!swapped){
            return;
        }
    } 
}
int main()
{
    int size; //Size of the arry
    cin>>size;
    int arr[size] ;
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr, size); //Function to sort the array
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}