#include<stdio.h>
int main()
{
    long long a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    if((a+b<=a+c)&&(b+c>=a+b) )
    {
        printf("%lld",a+b);
    }
    else if((a+c<=a+b)&&(a+c<=b+c) )
    {
        printf("%lld",a+c);
    }
    else if((b+c<=a+b)&&(a+c>=b+c))
    {
        printf("%lld",b+c);
    }
    return 0;
}