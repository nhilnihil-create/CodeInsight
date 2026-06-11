#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=1e5+9;

ll h[maxn];
ll n,a,b;

int check(ll mid)
{
    ll ans=mid;
    for(int i=1;i<=n;i++)
    {
        ll tt=h[i]-b*mid;
        if(tt>0)
        {
            ll cnt=tt/(a-b)+(tt%(a-b)==0?0:1);
            ans-=cnt;
            if(ans<0)return 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
    ll l=0,r=INF;
    ll ans=INF;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}
