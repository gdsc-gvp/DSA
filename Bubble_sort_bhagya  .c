#include<stdio.h>
int main()
{
    int arr[8],n,i,j,temp;
    printf("enter number of elements\n");
    scanf("%d",&n);
    printf("enter ALL  elements\n");
    for(i=0;i<n;i++)
    {
	    scanf("%d",&arr[i]);
    }
    printf("elements before bubble sorting\n");
    for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
    for (i=0;i<n-1;i++)
	{
	   for (j=i+1;j<n;j++)
		{
		  if (arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
    printf("elements after bubble sorting\n");
    for(i=0;i<=n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
OUTPUT:
enter number of elements
4
enter ALL  elements
23
32
11
10
elements before bubble sorting
23
32
11
10
elements after bubble sorting
10
11
23
32
