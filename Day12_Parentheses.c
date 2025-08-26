#include <stdio.h>
#include <string.h>
#define MAX 10005

int main()
{
    char s[MAX], stack[MAX], c, stack_top;
    int top=-1, i=0, valid=1;
    printf("Enter string of parentheses: ");
    scanf("%[^\n]",s);
    if (strlen(s)==0)
    {
        printf("True: Valid Parentheses!");
        return 0;
    }
    if (strlen(s) % 2 == 1)
    {
        printf("False: Invalid Parentheses!");
        return 0;
    }
    while(s[i]!='\0')
    {
        c=s[i];
        if (c=='(' || c=='{' || c=='[')
        {
            top++;
            stack[top]=c;
        }
        else
        {
            if(top==-1)
            {
                valid=0;
                break;
            }
            stack_top=stack[top];
            top--;
            if ((c==')' && stack_top!='(') || (c=='}' && stack_top!='{') || (c==']' && stack_top!='['))
            {
                valid=0;
                break;
            }
        }
        i++;
    }
    if (valid == 1 && top == -1)
    {
        printf("True: Valid Parentheses!");
    }
    else
    {
        printf("False: Invalid Parentheses!");
    }
    return 0;
}