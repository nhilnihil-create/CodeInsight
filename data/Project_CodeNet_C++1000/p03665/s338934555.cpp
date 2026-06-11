#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define mp make_pair
#define pb push_back
#define pf push_front
#define ss second
#define ff first
#define sz(x) (int)x.size()
#define newl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vl vector<ll>
#define pll pair<ll, ll>
#define vll vector<pll>
#define coutp cout << fixed << setprecision(12)
#define mem(x, val) memset(x, val, sizeof(x))
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define all(v) (v).begin(), (v).end()

const ld pi = 3.14159265359;
ll INF = 1e18 + 10;
ll MOD = 998244353;
ll mod = 1e9 + 7;

inline ll add(ll a, ll b, ll m)
{
    if ((a + b) >= m)
        return (a + b) % m;
    return a + b;
}

inline ll mul(ll a, ll b, ll m)
{
    if ((a * b) < m)
        return a * b;
    return (a * b) % m;
}

ll power(ll x, ll y, ll m)
{
    ll res = 1;
    x = x % m;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}

void solve()
{
    ll n,p;
    cin>>n>>p;
    ll od=0;
    for(int i=0;i<n;i++) {
        ll x;
        cin>>x;
        if(x%2) od++;
    }
    if(p==0&&od==0) {
        ll ans = (ll)1<<n;
        cout<<ans;
        return;
    }
    if(p==1&&od==0) {
        cout<<0;
        return;
    }
    //ll ev=n-od;
    //ll ans = 1<<ev;
    ll ans=(ll)1<<(n-1);
    cout<<ans;
}

int main()
{
    fastio;
    int t;
    t = 1;
    //cin >> t;
    //int test=t;
    
    while (t-- > 0)
    {
        //cout<<"Case #"<<(test-t)<<": ";
        solve();
        cout << newl;
    }

    return 0;
}