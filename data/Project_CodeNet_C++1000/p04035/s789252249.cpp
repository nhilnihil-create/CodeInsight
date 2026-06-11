// by adiforluls
#pragma GCC optimize ("-O2")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST            ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll              long long
#define ld              long double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define all(a)          (a).begin(),(a).end()
#define clz(a)          __builtin_clz(a) // count leading zeroes
#define ctz(a)          __builtin_ctz(a) // count trailing zeroes
#define popc(a)         __builtin_popcount(a) // count set bits (for ints only diff for ll)
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define rfor(i,a,b)     for(int i=a; i>=b; i--)
#define debug(x)        cerr << #x << " = " << x << endl;
#define F               first
#define S               second
#define endl            '\n'
#define SIZE            1000005
#define deci(n)         cout<<fixed<<setprecision(n)
#define ordered_set     tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key(k)
// find_by_order(k)
const ld PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll lul2 = 998244353;
const ll lul = 1000000007;

void mod(ll &x)
{
    if(x>=lul) x-=lul;
    if(x<0) x+=lul;
}

ll _gcd(ll a, ll b)
{
    if(b == 0) return a;
    return _gcd(b,a%b);
}

ll expo(ll n, ll p)
{
    if(p == 0) return 1;
    ll x = expo((n*n)%lul, p/2)%lul;
    if(p&1) return (x*n)%lul;
    return x;
}
//---------------------------------------------------------------------

void solve()
{
    int n,l; cin>>n>>l;
    int a[n];
    rep(i,0,n) cin>>a[i];
    int ans = -1;
    rep(i,0,n-1)
    {
        if(a[i]+a[i+1]>=l) ans = i+1;
    }
    if(ans == -1) {cout<<"Impossible"; return;}
    vector<int> order;
    rep(i,1,n)
    {
        if(i == ans) break;
        order.pb(i);
    }
    rfor(i,n-1,1)
    {
        if(i == ans) break;
        order.pb(i);
    }
    order.pb(ans);
    cout<<"Possible"<<endl;
    for(int i:order) cout<<i<<endl;
}
int main()
{   
    FAST;
   //  #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
   //  #endif
    int t; t=1;
    rep(i,1,t+1){
        solve();
    }
    return 0;
}