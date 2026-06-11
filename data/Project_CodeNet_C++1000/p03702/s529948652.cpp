#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
ll tail[100000+10];
bool pan(ll x)
{
    ll sum=0;
    for(ll i = 1;i<=n;++i)
    {
        ll t = tail[i] - x*b;
        if(t>0)
        {
            sum += (ll)ceil(t*1.0/(a-b));
            if(sum>x)
                return false;
        }
    }
    return true;
}
int main()
{
    ll imax=0;
    scanf("%lld%lld%lld",&n,&a,&b);
    for(ll i =1;i<=n;++i)
    {
        scanf("%lld",&tail[i]);
        imax=max(imax,tail[i]);
    }
    ll l = 0,r = imax,mid;
    while(l<r)
    {
        mid = l+r>>1;
        if(pan(mid))
            r = mid;
        else
            l = mid+1;
    }
    cout<<r<<'\n';
}
