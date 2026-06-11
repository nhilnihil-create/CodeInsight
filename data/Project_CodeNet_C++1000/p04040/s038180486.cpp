#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =2e5+10;
const int mod=1e9+7;

ll fac[maxn];
ll inv[maxn];

ll power(ll base,ll n)
{
    ll r=1;
    while(n)
    {
        if(n%2) r=r*base%mod;
        base=base*base%mod;
        n/=2;
    }
    return r;
}
void init()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
    inv[maxn-1]=power(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
    {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}

ll C(ll m,ll n)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll h,w,a,b;
    cin>>h>>w>>a>>b;
    init();
    ll ans=0;
    for(int i=1;i<=h-a;i++)
    {
        ll temp1=C(i-1,i+b+1-2);
        ll temp2=C(w-(b+2),h+w-(i+b+2));
        if(i==h-a)
            temp2=C(w-(b+1),h+w-(i+b+1));
        temp1%=mod;
        temp2%=mod;
        ll sum=temp1*temp2%mod;
        ans+=sum;
        ans%=mod;
    }
    cout<<ans<<'\n';


}
