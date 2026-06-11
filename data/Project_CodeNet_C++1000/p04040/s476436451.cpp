#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define maxn 200005
const ll mod=1e9+7;
using namespace std;
ll fac[maxn];
ll h,w,a,b;

ll quickpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans%mod;
}
void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<maxn;i++)
        fac[i]=(fac[i-1]*1LL*i)%mod;
}
ll getc(ll n,ll m)
{
    if(m==0||m==n)
        return 1;
    ll res=fac[n];
 res=res*quickpow(fac[n-m],mod-2)%mod;
 res=res*quickpow(fac[m],mod-2)%mod;
 return res;
}
int main()
{
    scanf("%lld%lld%lld%lld",&h,&w,&a,&b);
    init();
    ll res;
    ll ans=0;
    for(ll i=b+1;i<=w;i++)
    {
        res=getc(i-1+h-a-1,h-a-1)*getc(a-1+w-i,a-1)%mod;
        ans=(ans%mod+res%mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;

}
