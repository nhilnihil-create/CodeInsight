#include <stdio.h>

long long ggccdd(long long a,long long b)
{
    if (a%b==0) return b;
    if (a>b) return ggccdd(a%b,b);
    else return ggccdd(b%a,a);
}

int main()
{
    long long n,x;
    scanf("%lld%lld",&n,&x);
    long long gcd=ggccdd(n,x);
    long long ans=n/gcd;
    ans*=3;ans-=3;ans*=gcd;
    printf("%lld\n",ans);
}
