#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;

struct Edge {
    ll from;
    ll to;
    ll cost;
    Edge() { from = to = cost = 0; }

    Edge(ll f, ll t, ll c) {
        from = f;
        to = t;
        cost = c;
    }
};


void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(m), b(m), c(m);
    rep(i, m) cin >> a[i] >> b[i] >> c[i];

    vector<Edge> edges(m);
    rep(i, m) {
        edges[i] = Edge(a[i]-1, b[i]-1, -c[i]);
    }

    ll INF = 1e18;
    vector<ll> d(n, INF);
    d[0] = 0;

    rep(_i, n) {
        for (auto& e: edges) {
            ll v = d[e.from] + e.cost;
            if (d[e.from] != INF && d[e.to] > v) {
                d[e.to] = v;
                // n-1を含む無限ループがあるか
                if (_i == n - 1 && e.to == n - 1) {
                    // negative loop
                    put("inf");
                    return;
                }
            }
        }
    }

    put(-d[n-1]);
}
signed main(){ Main();return 0;}