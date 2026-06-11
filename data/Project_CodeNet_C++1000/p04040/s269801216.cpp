#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ld long double
typedef pair<ll,ll> pii;
const int maxn=200005;
const int mod=1e9+7;
ll qp(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ret;
}
ll jc[maxn],inv[maxn];
void init()
{
    jc[0]=1;
    for(int i=1;i<=200004;i++) jc[i]=jc[i-1]*i%mod;
    inv[200004]=qp(jc[200004],mod-2);
    for(int i=200003;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int x,int y)
{
    return jc[x]*inv[x-y]%mod*inv[y]%mod;
}
ll calc(int x,int y)
{
    return C(x+y-2,x-1);
}
int main()
{
    #ifdef local
    freopen("in.txt","r",stdin);
    #endif // local
    IOS;
    init();
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    ll ans=0;
    for(int i=h-a+1;i<=h;i++)
    {
        ans+=calc(i,b)*calc(h-i+1,w-b)%mod;
        ans%=mod;
    }
    ans=calc(h,w)-ans;
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
}
