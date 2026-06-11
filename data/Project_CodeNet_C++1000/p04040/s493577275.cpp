#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
//#define db double
#define all(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
#define mem(x, y) memset(x, y, sizeof(x))
#define what_is(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << (x) << endl;
#define suf_zero(x) __builtin_ffs(x)
#define pre_zero(x) __builtin_clz(x)
#define num_one(x) __builtin_popcount(x)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define INFI 2000000009
#define INFLL (ll)1e18+7
#define fi first
#define se second
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
#define PII pair<int, int>
#define rep(i, begin, end) for(__typeof(end) i =(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
void err(istream_iterator<string> it) {cerr<<endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " , ";
    err(++it, args...);
}
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//using namespace __gnu_pbds;
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9+7;
ll qp(ll b, ll n){ll r=1;b%=mod;if(n<0) n+=mod-1;for(;n;n>>=1, b=b*b%mod)if(n&1) r=r*b%mod;return r;}
//#define RG register
///////////// BOUND /////////////////
//tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;
/////////////// MACRO ///////////////
const int maxn = 4e5+7;
ll fac[maxn], finv[maxn];
ll C(int n, int m)
{
    if(n<m||m<0) return 0;
    return fac[n]*finv[m]%mod*finv[n-m]%mod;
}
int main()
{
    int n, m, a, b;cin>>n>>m>>a>>b;
    fac[0]=finv[0]=1;
    for(int i=1;i<maxn;++i) fac[i] = fac[i-1]*i%mod;
    finv[maxn-1] = qp(fac[maxn-1], mod-2);
    for(int i=maxn-2;i>=1;--i) finv[i] = finv[i+1]*(i+1)%mod;
    ll ans = C(n+m-2, n-1);
    for(int i=0;i<b;++i)
        ans = (ans-C(n-a-1+i, i)*C(a-1+m-1-i, m-1-i)%mod+mod)%mod;
    cout << ans << endl;
}