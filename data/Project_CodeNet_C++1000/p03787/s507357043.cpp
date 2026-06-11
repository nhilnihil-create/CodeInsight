#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> col(n, -1);
    bool ok;
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : g[v]) {
            if (to == p) continue;
            if (col[to] == col[v]) {
                ok = false;
            }
            if (col[to] == -1) {
                col[to] = col[v] ^ 1;
                dfs(to, v);
            }
        }
    };
    ll a = 0, b = 0;
    ll ans = 0, all = n;
    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            ok = true;
            col[i] = 0;
            dfs(i, -1);
            if (g[i].size() == 0) {
                all--;
            } else if (ok) {
                a++;
            } else {
                b++;
            }
        }
    }
    b += a;
    ans += n * n - all * all;
    ans += b * b + a * a;
    cout << ans << '\n';
    return 0;
}