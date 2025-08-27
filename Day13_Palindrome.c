#include<stdio.h>
#include<string.h>
#define MAX 1005
int start=0, max=1;
char s[MAX];
void check_longest_palindrome(int n, int left, int right)
{
    while(left>=0 && right<n && s[left]==s[right])
    {
        if(right-left+1 > max)
        {
            start=left;
            max=right-left+1;
        }
        left--;
        right++;
    }
}
int main()
{
    printf("Enter the string: ");
    scanf("%[^\n]",s);
    int n=strlen(s), left,right;
    if(n==0)
    {
        printf("No string to check!");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        check_longest_palindrome(n, i, i);
        check_longest_palindrome(n, i, i+1);
    }
    printf("Longest Palindromic Substring: ");
    for(int i=start;i<start+max;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}