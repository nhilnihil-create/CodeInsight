#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
#define ll long long
#define re register
#define pb push_back
#define fi first
#define se second
const int N=4e6+10;
const int mod7=1e9+7;
const int mod=1e9+7;
void read(int &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0')
        if(ch=='-')
            d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9')
        a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
void read(ll &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0')
        if(ch=='-')
            d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9')
        a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
ll f[2005][2005],fac[N],ifac[N];
ll quickmod(ll x,ll y)
{
    ll res=1,base=x;
    while(y)
    {
        if(y&1) res=res*base%mod;
        base=base*base%mod;
        y>>=1;
    }
    return res;
}
void init(int n)
{
    fac[0]=1;
    for(re ll i=1;i<=n;i++) fac[i]=i*fac[i-1]%mod;
    ifac[n]=quickmod(fac[n],mod-2);
    for(re ll i=n-1;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}
ll C(int n,int m) {return n<m?0:((fac[n]*ifac[m]%mod)*ifac[n-m])%mod;}
int main()
{
    int n,k;
    read(n),read(k);
    if(k==1) return puts("1"),0;
    init(4000000);
    f[0][0]=1;
    for(re int i=1;i<=n;i++)
    {
        for(re int j=0;j<=i;j++)
        {
            if(!j)
            {
                f[i][j]=f[i-1][j];
                continue;
            }
            f[i][j]=f[i-1][j]+f[i][j-1]*(n-j+1)%mod*C(n*k-i-1-(j-1)*(k-1),k-2)%mod;
            f[i][j]%=mod;
        }
    }
    printf("%lld\n",f[n][n]);
    return 0;
}