#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define rg register
#define ll long long
#define mod 1000000007
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
ll fac[1000005],inv[1000005];
ll qpow(ll b,ll p)
{
    ll ans=1;
    while(p)
    {
        if(p&1) ans=ans*b%mod;
        b=b*b%mod;
        p>>=1;
    }
    return ans;
}
void init(int x)
{
    fac[0]=1;
    for(rg int i=1;i<=x;i++)
        fac[i]=fac[i-1]*i % mod;
    inv[x]=qpow(fac[x],mod-2);
    for(rg int i=x-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int x,int y)
{
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
   
    int n,m,x,y;
    n=read(),m=read(),x=read(),y=read();
    init(n+m);
    ll ans=0;
    for(int i=1;i<=y;i++)
    {
        ll tem=C(i-1+n-x-1,n-x-1)*C(x-1+m-i,m-i)%mod;
        ans=(ans+tem)%mod;
    }
    ll an=(C(n-1+m-1,n-1)-ans+mod)%mod;
    printf("%lld\n",an);
    return 0;
}