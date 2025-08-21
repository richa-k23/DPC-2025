#include<stdio.h>
int main()
{
    int n, result=0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int height[n];
    printf("Enter %d non-negative heights: \n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&height[i]);
    }
    if(n>=3)
    {
        int left_max[n], right_max[n], min_height;
        left_max[0]=height[0];
        right_max[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            if (height[i] > left_max[i-1])
            {
                left_max[i]=height[i];
            }
            else
            {
                left_max[i]=left_max[i-1];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(height[i]>right_max[i+1])
            {
                right_max[i]=height[i];
            }
            else
            {
                right_max[i]=right_max[i+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(left_max[i]<right_max[i])
            {
                min_height=left_max[i];
            }
            else
            {
                min_height=right_max[i];
            }
            result += (min_height - height[i]);
        }
    }

    printf("The total amount of water trapped = %d units.", result);
    return 0;
}