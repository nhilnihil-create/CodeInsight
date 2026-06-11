#include <stdio.h>
#include <math.h>

int main()
{
    long long int n,a,b;

    scanf("%lld %lld %lld",&n,&a,&b);


    if(a==b)
    {
        printf("1");
    }


    else if(n==1)
    {
        printf("0");
    }

    else if(b<a)
    {
        printf("0");
    }

    else
    {
       printf("%lld",((b-a)*(n-2))+1);
    }


    return 0;
}
