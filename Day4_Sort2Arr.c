#include<stdio.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int next_gap(int gap)
{
    if(gap<=1) return 0;
    return (gap/2) + (gap%2);
}
void sort(int arr1[],int arr2[],int n1,int n2)
{
    int i,j;
    int gap=next_gap(n1+n2);
    while(gap>0)
    {
        for(i=0;i+gap<n1;i++)
        {
            if(arr1[i]>arr1[i+gap])
            {
                swap(&arr1[i],&arr1[i+gap]);
            }
        }
        j=(gap>n1)?gap-n1:0;
        while(i<n1 && j<n2)
        {
            if(arr1[i]>arr2[j])
            {
                swap(&arr1[i],&arr2[j]);
            }
            i++;
            j++;
        }
        if (j<n2)
        {
            for (j=0;j+gap<n2;j++)
            {
                if (arr2[j]>arr2[j+gap])
                {
                    swap(&arr2[j],&arr2[j+gap]);
                }
            }
        }
        gap=next_gap(gap);
    }
}
int main()
{
    int n1,n2;
    printf("Enter size of the 2 arrays: ");
    scanf("%d %d",&n1,&n2);
    int arr1[n1], arr2[n2];
    printf("Enter %d elements in the first array: \n",n1);
    for (int i=0;i<n1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter %d elements in the second array: \n",n2);
    for (int i=0;i<n2;i++)
    {
        scanf("%d",&arr2[i]);
    }

    sort(arr1,arr2,n1,n2);

    printf("After sorting both arrays: \nArray 1: ");
    for(int i=0;i<n1;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\nArray 2: ");
    for(int i=0;i<n2;i++)
    {
        printf("%d ",arr2[i]);
    }
    return 0;
}