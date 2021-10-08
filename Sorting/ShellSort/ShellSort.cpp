#include<iostream>
 
using namespace std;
 
// Function implementing Shell sort.
void ShellSort(int a[], int n)
{
	int i, j, k, temp;
	//Initially Gap 'i=n/2' between index of the element to be compared.
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				// If value at higher index is greater, then break the loop.
				if(a[k+i] >= a[k])
				break;
				// Switch the values otherwise.
				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
				}
			}
		}
	}
}
int main()
{	
	int arr[] = {12,14,8,26,9,4,23,16,7,3}, n = 10, i;

	ShellSort(arr, n);
	// Printing the sorted data.
	cout<<"\nSorted Data: ";
	for (i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	return 0;
}