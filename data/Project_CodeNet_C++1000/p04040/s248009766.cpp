//I am so vegetable
//#define err
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define in insert
#define er erase
#define ct count
#define ep empty
#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define _rfor(i,a,b) for(int i = (a);i>(b);--i)
#define _sfor(p,st) for(auto &p:st)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1.0);
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll x, ll y) { ll ans = 1; for (; y > 0; y >>= 1) { if (y & 1)ans *= x; x *= x; }return ans; }
ll qpow(ll x, ll y, int MOD) { ll ans = 1; for (; y > 0; y >>= 1) { if (y & 1)ans = ans*x%MOD; x = x*x%MOD; }return ans; }
void exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1;y=0;return;}
    exgcd(b,a%b,x,y);
    ll X=x;
    x=y; y=X-a/b*y;
}
ll inv(ll x, int mod = MOD) { return qpow(x, mod - 2,mod); }
ll m_m(ll a){ return (a%MOD+MOD)%MOD; }


const int MAX=100005;
ll a[MAX<<1+5],inva[MAX<<1+5];
ll C(ll n,ll m){
    return a[n]*inva[m]%MOD*inva[n-m]%MOD;
}
signed main() {
    //ifstream cin("E:\\acm dream\\in.in");
	//ofstream cout("E:\\acm dream\\out.out");
	FIO;
    #ifdef err
	double be = clock();
    #endif

    a[0]=1;
    _for(i,1,MAX<<1+1)a[i]=a[i-1]*i%MOD;
    inva[0]=1;
    inva[MAX<<1]=inv(a[MAX<<1]);
    _rfor(i,(MAX<<1)-1,0)inva[i]=inva[i+1]*(i+1)%MOD;
    ll n,m;cin>>n>>m;
    ll x,y;cin>>x>>y;
    ll ans=0;
    _for(i,y+1,m+1){
        ans+=C(n-x+i-2,i-1)*C(x+m-i-1,m-i)%MOD;
        ans%=MOD;
    }
    cout<<ans;

    #ifdef err
	double en = clock();
    cout<<"time: "<<fixed<<setprecision(8)<<en-be;
    #endif
	return 0;
}