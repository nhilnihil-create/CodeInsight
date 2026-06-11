#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e5+10;
const int mod=1e9+7;
ll x[maxn],y[maxn];
ll n,m;
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld",&y[i]);
    ll sumx=0,sumy=0;
    for(ll i=1;i<=n;i++)
    {
        sumx=(sumx+(i-1)*x[i]%mod-(n-i)*x[i]%mod+mod)%mod;
    }
    for(ll i=1;i<=m;i++)
    {
        sumy=(sumy+(i-1)*y[i]%mod-(m-i)*y[i]%mod+mod)%mod;
    }
    //cout<<sumx<<" "<<sumy<<endl;
    printf("%lld\n",(sumx*sumy)%mod);
}
