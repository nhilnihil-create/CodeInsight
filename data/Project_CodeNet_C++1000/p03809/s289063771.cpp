// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T& x, const T& y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T& x, const T& y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    
    if (n == 2) {
        cout << (a[0] == a[1] ? "YES\n" : "NO\n");
        return 0;
    }
    int root = -1;
    rep(i, n) {
        if (sz(g[i]) >= 2) root = i;
    }
    auto dfs = [&](auto f, int v, int p) -> ll {
        if (sz(g[v]) == 1) return a[v];
        ll sum = 0;
        for (int u: g[v]) {
            if (u == p) continue;
            ll x = f(f, u, v);
            if (x > a[v]) {
                cout << "NO\n";
                exit(0);
            }
            sum += x;
        }
        ll one = a[v] * 2 - sum;
        ll two = a[v] - one;
        if (one < 0 || two < 0 || one > a[v] || two > a[v]) {
            cout << "NO\n";
            exit(0);
        }
        return one;
    };
    cout << (dfs(dfs, root, -1) == 0 ? "YES\n" : "NO\n");
    return 0;
}
