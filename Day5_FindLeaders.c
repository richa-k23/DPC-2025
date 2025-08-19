#include<stdio.h>

int main()
{
    int n, k=0;
    printf("Enter the total number of elements in the array: ");
    scanf("%d",&n);
    int arr[n],result[n];
    printf("Enter %d elements in the array: \n",n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int max=arr[n-1];
    result[k++]=max;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            result[k++]=arr[i];
        }
    }

    printf("Leaders: ");
    for(int i=k-1;i>=0;i--)
    {
        printf("%d ",result[i]);
    }
    return 0;
}