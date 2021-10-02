/*Recursive Implementation of binary search */

#include <iostream>
using namespace std;


int bSearch(int arr[], int low, int high, int x)
{
	if(low > high)
		return -1;  //prints -1 if element not present 

	int mid = (low + high) / 2;

	if(arr[mid] == x)
		return mid;

	else if(arr[mid] > x)
		return bSearch(arr, low, mid - 1, x);

	else
		return bSearch(arr, mid + 1, high, x);
}

int main() {
    int n;
    cout<<"Enter the no.of elements in the array :";
    cin>>n;
    cout<<"Enter the elements in the array :";
    int arr[n];
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
         
     }

	int x;
	cout<<"Enter the element to be searched : ";
	cin>>x;
	cout<<bSearch(arr, 0, n - 1, x);
	return 0;
}
