#include<stdio.h>
int main()
{
    int n,k;
    printf("enter size of the array: ");
    scanf("%d",&n);
    printf("enter key: ");
    scanf("%d",&k);
    int arr[n];
    printf("enter the elements in the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int found = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            printf("element found at %d position",i+1);
            found = 1;   //if element is found in the array
            break;
        }
    }
    if(found == 0)
    {
        printf("Element not found in array\n");
    }
    
return 0;
}
