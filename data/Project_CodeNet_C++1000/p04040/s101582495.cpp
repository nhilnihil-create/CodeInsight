#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mod 1000000007
#define maxn 100010
using namespace std;
typedef long long ll;
ll n,m,a,b;
ll quick_pow(ll x,ll p)
{
    ll an=1;
    ll po=x;
    while(p)
    {
        if(p%2)  an=(an*po)%mod;
        po=(po*po)%mod;
        p/=2;
    }
    return an;
}
ll fac[maxn*2],inv[maxn*2];
ll f[maxn];
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
    fac[0]=1;
    for(ll i=1;i<=2*max(n,m);i++)  fac[i]=(fac[i-1]*i)%mod;
    for(ll i=0;i<=2*max(n,m);i++)  inv[i]=quick_pow(fac[i],mod-2);
    for(int i=1;i<=n-a;i++)  f[i]=fac[i+b-2]*inv[i-1]%mod*inv[b-1]%mod;
    for(int i=1;i<=n-a;i++)  f[i]=f[i]*fac[n-i+m-b-1]%mod*inv[m-b-1]%mod*inv[n-i]%mod;
    ll ans=0;
    for(int i=1;i<=n-a;i++)  ans=(ans+f[i])%mod;
    printf("%lld\n",ans);
    return 0;
}