#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
const int N=200010;
const int mod=1e9+7;

int h,w,a,b;
int fac[N],fnv[N];
ll ans;
ll quickmod(ll x,ll y)
{
    ll ans=1;
    for(;y;y>>=1)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
    }
    return ans;
}

void build()
{
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%mod;
    fnv[N-1]=quickmod(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) fnv[i]=1ll*fnv[i+1]*(i+1)%mod;
}

ll C(int x,int y)
{
    if(x<y) return 0;
    return 1ll*fac[x]*fnv[y]%mod*fnv[x-y]%mod;
}

int main()
{
    build();
    scanf("%d%d%d%d",&h,&w,&a,&b);
    for(int i=b+1;i<=w;i++)
    {
        ans=(ans+C(h-a-2+i,i-1)*C(a-1+w-i,w-i)%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}

