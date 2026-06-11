#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=2e5+5;
ll f[maxn],invf[maxn];
ll qpow(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
void init()
{
    invf[0]=f[0]=1;
    for(ll i=1;i<maxn;i++)
        f[i]=f[i-1]*i%mod;
    invf[maxn-1]=qpow(f[maxn-1],mod-2);
    for(ll i=maxn-2;i>0;i--)
        invf[i]=invf[i+1]*(i+1)%mod;
}
ll c(ll a,ll b)
{
    ll n=a+b-2;
    ll m=a-1;
    return f[n]*invf[n-m]%mod*invf[m]%mod;
}
int main()
{
    init();
    int h,w,a,b;
    while(~scanf("%d%d%d%d",&h,&w,&a,&b))
    {
        ll ans=0;
        for(int i=b+1;i<=w;i++)
        {
            ans=(ans+c(h-a,i)*c(a,w-i+1)%mod)%mod;
        }
        printf("%lld\n",ans);
    }
}

