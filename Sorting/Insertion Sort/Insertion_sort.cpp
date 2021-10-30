/* Cpp Program to sort an array  using Insertion Sort */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j,x;
 /* i,j variables for loops x variable for choice*/ 
    cout<<"Enter number of elements\n";//Accepting size of array
    cin>>n;
 	int arr[n][2]; //Declaring 2-d array to store their indices as well
    cout<<"Enter "<<n<<" integers"<<endl;
    for (i = 0; i < n; i++)
    {
        cin>>arr[i][0];
		arr[i][1]=i+1;// Storing their indices
	}
	cout<<"Enter 1 to sort elements in ascending order\nEnter 2 to sort elements in descending order\n";// Taking choice from user
	cin>>x;
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
	    if(x==1)
	    {
            while ( j > 0 && arr[j-1][0] > arr[j][0])//Checking condition for ascending order
            {	
	    arr[j][0]=arr[j][0]+arr[j-1][0]-(arr[j-1][0]=arr[j][0]);/* Swapping both element as well as its index */
	    arr[j][1]=arr[j][1]+arr[j-1][1]-(arr[j-1][1]=arr[j][1]);   
                j--;
            }}
	    else if(x==2)
	    {
            while ( j > 0 && arr[j-1][0] < arr[j][0])//Checking condition for ascending order
            {	
	    arr[j][0]=arr[j][0]+arr[j-1][0]-(arr[j-1][0]=arr[j][0]);
	    arr[j][1]=arr[j][1]+arr[j-1][1]-(arr[j-1][1]=arr[j][1]);
                j--;
            }}
	    else
	    {
	    cout<<"Enter correct input";
	    return 0;// terminating program if user enters wrong choice
    }}
    cout<<"Sorted list  with their initial indices attached:\n";
    for (i = 0; i <= n - 1; i++)//Printing sorted array
    {
        cout<<arr[i][0]<<"-"<<arr[i][1]<<" ";
    }
    return 0;
}
