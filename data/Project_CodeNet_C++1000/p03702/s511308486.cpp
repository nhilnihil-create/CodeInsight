#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#define eps 1e-7;
typedef long long ll;
using namespace std;
const int maxn=100005;

ll h[maxn],hi;
//ll hi[maxn];
ll a,n,b;
ll in=1e10;

bool c(ll x)
{
    ll t=x;
   // for(ll i=0;i<n;i++)
    //    hi[i]=h[i];
    for(ll i=0;i<n;i++)
    {
        hi=h[i];
        hi-=x*b;
        if(hi<=0) continue;
        ll y;
        if(hi%(a-b)==0)
            y=hi/(a-b);
        else
            y=hi/(a-b)+1;
        t-=y;
    }
    if(t>=0)
        return true;
    return false;
}

void slove()
{
    sort(h,h+n);
    ll l=0,r=in;
    while(r-l>1)
    {
        ll mid=(r+l)/2;
        if(c(mid))
            r=mid;
        else
            l=mid;
    }
    printf("%lld\n",r);
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    slove();
    return 0;
}
