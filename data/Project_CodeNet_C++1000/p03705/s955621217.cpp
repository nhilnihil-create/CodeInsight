#include <stdio.h>

#define endl '\n'

int main()
{
    long long n, a, b, min, max;
    scanf("%lld %lld %lld", &n, &a, &b);

    if(a>b) printf("0");
    else if(n==1 && a-b) printf("0");

    else
    {
        min=a+b+a*(n-2);
        max=a+b+b*(n-2);

        printf("%lld", max-min+1);
    }
    return 0;
}
