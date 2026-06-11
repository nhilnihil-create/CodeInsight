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
    int n, m;
    cin >> n >> m;
    vector<ll> d(n, 1e18);
    vector<int> from(m), to(m);
    vector<ll> cost(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> cost[i];
        from[i]--, to[i]--;
        cost[i] = -cost[i];
        g[to[i]].emplace_back(from[i]);
    }
    d[0] = 0;
    vector<int> y(n), x;
    function<void(int)> dfs = [&](int v) {
        y[v] = 1;
        for (int to : g[v]) {
            if (y[to]) {
                continue;
            }
            dfs(to);
        }
    };
    dfs(n - 1);
    for (int i = 0; i < m; i++) {
        if (y[from[i]] && y[to[i]]) {
            x.emplace_back(i);
        }
    }
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            cout << "inf" << '\n';
            return 0;
        }
        bool ok = true;
        for (int j : x) {
            if (d[to[j]] > d[from[j]] + cost[j]) {
                d[to[j]] = d[from[j]] + cost[j];
                ok = false;
            }
        }
        if (ok) {
            break;
        }
    }
    cout << -d[n - 1] << '\n';
    return 0;
}