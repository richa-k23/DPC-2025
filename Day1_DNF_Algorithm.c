#include<stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n;
    printf("Enter total number of elements in the array: ");
    scanf("%d",&n);
    if (n==0)
    {
        printf("Error: Empty Array!");
        return 0;
    }
    int arr[n];
    printf("Enter %d elements in the array (0/1/2): \n",n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if (arr[mid]==0)
        {
            swap(&arr[low],&arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(&arr[mid],&arr[high]);
            high--;
        }
    }

    printf("Sorted Array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}