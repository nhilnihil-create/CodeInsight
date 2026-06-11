#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int n;
V<ll> a;
V<V<int>> G;

void dfs(int v, int par) {
    if(G[v].size() == 1) return;
    ll sum = 0, mx = 0;
    for(int u : G[v]) {
        if(u == par) continue;
        dfs(u, v);
        sum += a[u];
        chmax(mx, a[u]);
    }
    if(a[v] > sum || sum > 2 * a[v]) {
        cout << "NO" << endl;
        exit(0);
    }
    ll k = sum - a[v];
    if(k > sum - mx) {
        cout << "NO" << endl;
        exit(0);
    }
    a[v] -= k;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    a.resize(n);
    G.resize(n);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n == 2) {
        cout << (a[0] == a[1] ? "YES" : "NO") << endl;
        return 0;
    }
    int v = 0;
    while(G[v].size() == 1)
        v++;
    dfs(v, -1);
    cout << (a[v] == 0 ? "YES" : "NO") << endl;

    return 0;
}