#include<stdio.h>
int main()
{
    int n;
    printf("Enter the total number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements in the array: \n",n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int slow=arr[0], fast=arr[0];
    do
    {
        slow=arr[slow];
        fast=arr[arr[fast]];
    } while (slow!=fast);
    slow=arr[0];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    printf("Duplicate number: %d",slow);
    return 0;
}