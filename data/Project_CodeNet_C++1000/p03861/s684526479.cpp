#include <stdio.h>
int main(void)
{
    long long int a,b,x,c,d,e;
    scanf("%lld %lld %lld",&a,&b,&x);
    if(a==0)
    {
        e=(b/x)+1;
    }
    else
    {
        c=(a-1)/x;
        d=b/x;
        e=d-c;
    }

    printf("%lld",e);
    return 0;

}