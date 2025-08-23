#include <stdio.h>
#include <string.h>
int main() 
{
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    if (n == 0) 
    {
        printf("Longest Common Prefix: \"\"\n");
        return 0;
    }
    char strs[n][201]; 
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", strs[i]);
    }
    char prefix[201];
    strcpy(prefix, strs[0]);
    for (int i = 1; i < n; i++) 
    {
        int j = 0;
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]) 
        {
            j++;
        }
        prefix[j] = '\0'; 
        if (prefix[0] == '\0') 
        {
            break;
        }
    }
    printf("Longest Common Prefix: \"%s\"\n", prefix);
    return 0;
}