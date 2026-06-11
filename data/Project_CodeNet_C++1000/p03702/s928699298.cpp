#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxN=1e5+5;

ll a[maxN],n,A,B;

bool check(ll x)
{
    ll k,sum=0;
    for(k=1;k<=n;k++)
    {
        if(a[k]-x*B<=0)continue;
        sum+=(a[k]-x*B)/(A-B);
        if((a[k]-x*B)%(A-B)!=0)sum++;
    }
    return sum<=x;
}

int main()
{
    ll k,l,r,mid;
    scanf("%lld%lld%lld",&n,&A,&B);
    for(k=1;k<=n;k++)
        scanf("%lld",&a[k]);
    l=1;r=1e9;
    while(r-l>5)
    {
        mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    for(;l<=r;l++)
        if(check(l))break;
    printf("%lld",l);
    return 0;
}
