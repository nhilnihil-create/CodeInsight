#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using base = complex<double>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define M2 998244353
#define ll long long
#define pll pair<long, long>
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define ff first
#define ss second
#define pb push_back
#define db pop_back
#define mp make_pair
#define mt make_tuple
#define g(a, b) get<a>(b)
#define INF (ll)1e18 + 100
#define vl vector<ll>
#define vi vector<int>
#define vll vector<pair<ll, ll>>
#define vii vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))
#define INT_SIZE 32
/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x − 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/

#define o_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define o_setll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
ll powM(ll x, ll y, ll m)
{
    ll ans = 1, r = 1;
    x %= m;
    while (r > 0 && r <= y)
    {
        if (r & y)
        {
            ans *= x;
            ans %= m;
        }
        r <<= 1;
        x *= x;
        x %= m;
    }
    return ans;
}
ll modI(ll a, ll m)
{
    ll m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

ll logint(ll x, ll y)
{
    ll ans = 0;
    ll a = 1;
    for (ll i = 0; i <= x; i++)
    {
        if (x < a)
        {
            return ans;
        }
        ans++;
        a *= y;
    }
    return -1;
}
ll extended(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
ll lcm(ll x, ll y) {
    return (x * y) / (__gcd(x, y));
}

const int N = 105;
bool is_shortest[N][N];
bool is_edge[N][N];
vll adj[N];
void solve() {
    ll n, m ;
    cin >> n >> m;
    REP(j, 0, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        is_edge[a][b] = true;
        is_edge[b][a] = true;
        adj[a].pb({c, b});
        adj[b].pb({c, a});
    }
    REP(i, 1, n + 1) {
        vector<bool>vis(n + 1, false);
        vl dist(n + 1, INF);
        priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>pqt;
        pqt.push({0, {i, i}});
        while (!pqt.empty()) {
            pair<ll, pair<ll, ll>>p = pqt.top();
            pqt.pop();
            if (dist[p.ss.ff] < p.ff) {continue;}
            else if (dist[p.ss.ff] == p.ff) {
                is_shortest[p.ss.ff][p.ss.ss] = true;
                is_shortest[p.ss.ss][p.ss.ff] = true;
            }
            else {
                dist[p.ss.ff] = p.ff;
                is_shortest[p.ss.ff][p.ss.ss] = true;
                is_shortest[p.ss.ss][p.ss.ff] = true;
                for (auto y : adj[p.ss.ff]) {
                    if (dist[y.ss] >= dist[p.ss.ff] + y.ff) {
                        pqt.push({dist[p.ss.ff] + y.ff, {y.ss, p.ss.ff}});
                    }
                }
            }
        }
    }
    ll ans = 0;
    REP(i, 1, n + 1) {
        REP(j, i + 1, n + 1) {
            if (!is_shortest[i][j] && is_edge[i][j]) {
                ans++;
            }
        }
    }
    cout << ans;
    // ans /= 2;
    // cout << m - ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("b1.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll ntc;
    // cin >> ntc;
    ntc = 1;
    REP(tc, 1, ntc + 1)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
}