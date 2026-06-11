#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=2e5;
ll p[maxn+10];
ll inv[maxn+10];
int H,W,A,B;
ll mul(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ret;
}
void init()
{
    p[0]=1;
    for(int i=1;i<=maxn;i++)
        p[i]=p[i-1]*i%mod;
    inv[maxn]=mul(p[maxn],mod-2);
    for(int i=maxn-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;

}
ll C(ll n,ll m)
{
    if(n==m)
        return 1;
    if(n<m)
        return 0;
    return p[n]*inv[m]%mod*inv[n-m]%mod;
}
ll sovle()
{
    ll ret=0;
    for(int i=1;i<=(H-A);i++)
    {
        ret=(ret+C(i+B-2,i-1)*C((H-i+1)+W-B-2,H-i)%mod)%mod;
    }

    return ret;
}
int main()
{
    init();
    while(cin>>H>>W>>A>>B)
    {
        printf("%lld\n",sovle());
    }
    return 0;
}