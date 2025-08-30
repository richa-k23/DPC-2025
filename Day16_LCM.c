#include<stdio.h>
int GCD(long long a, long long b)
{
    long long temp;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
long long LCM(long long a, long long b)
{
    return (a/GCD(a,b)) * b;
}
int main()
{
    long long n, m, result;
    printf("Enter two integers: ");
    scanf("%lld %lld", &n, &m);
    result=LCM(n,m);
    printf("LCM of %lld and %lld is: %lld", n, m, result);
    return 0;
}