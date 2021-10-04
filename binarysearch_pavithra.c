write a program to binary search an elemnt in c language
#include<stdio.h>
int main()
{
    int arr[4];
    int n;
    int i;
    int low;
    int high;
    int mid;
    int x;
    printf("no of elements in array\n");
    scanf("%d",&n);
    printf("elements are \n");
    for (i=0;i<n;i++)
    {
	scanf("%d",&arr[i]);
    }
    printf("enter x");
    scanf("%d",&x);
    low=0;
    high= n-1;
    mid =low+(high-low)/2 ;
    while(low<=high)
    {
	if (arr[mid] < x)
        low= mid + 1;
        else if (arr[mid] == x) 
	   {
              printf("%d found at location %d.\n", x, mid+1);
                break;
            }
         else
         high = mid - 1;                           
         mid = (low + high)/2;
     }
    if (low > high)
   printf("Not found! %d isn't present in the list.\n", x);
}

output
no of elements in array
 7
elements are
1 2 4 6 8 9 11
enter x 8
8 found at location 5.

  
  
