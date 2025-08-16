#include<stdio.h>
int main()
{
    int n, sum=0, actual=0, missing;
    printf("Enter the total number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements in the array (sorted): \n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    actual=((n+1)*(n+2))/2;
    printf("Missing Element from the array is: %d", actual-sum);
    return 0;
}