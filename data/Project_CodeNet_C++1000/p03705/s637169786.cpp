#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,a,b;

int main()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    if(a>b||(n<2&&a!=b))
    {
        puts("0");
        return 0;
    }
    n-=2;
    printf("%lld\n",n*b-n*a+1);
    return 0;
}