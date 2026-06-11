#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

struct edge {
    ll to;
    ll cost;
};

int n;
vector<vector<edge>> g;
vector<ll> d;

void dfs(ll s, ll di, ll pa = -1) {
    d[s] = min(d[s], di);

    for (auto t : g[s]) {
        if (t.to == pa) continue;

        dfs(t.to, di + t.cost, s);
    }
}

int main() {

    cin >> n;

    g.resize(n);
    d.resize(n, LINF);

    for (int i = 0; i < n - 1; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        --a; --b;

        g[a].push_back(edge({b, c}));
        g[b].push_back(edge({a, c}));
    }

    ll q, k; cin >> q >> k;
    --k;

    dfs(k, 0);

    for (int i = 0; i < q; ++i) {
        ll x, y; cin >> x >> y;
        --x; --y;

        ll ans = d[x] + d[y];

        cout << ans << endl;
    }
}