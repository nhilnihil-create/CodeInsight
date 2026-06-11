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
    int n;
    cin >> n;
    if (n == 2) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        return 0;
    }
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 1) {
            root = i;
            break;
        }
    }
    function<ll(int, int)> dfs = [&](int v, int p) {
        vector<ll> t;
        for (int to : g[v]) {
            if (to == p) continue;
            t.emplace_back(dfs(to, v));
        }
        if (t.empty()) {
            return a[v];
        }
        sort(t.begin(), t.end());
        ll mx = accumulate(t.begin(), t.end(), 0LL);
        ll mn = max(t.back(), (mx + 1) / 2);
        if (a[v] < mn || mx < a[v]) {
            cout << "NO" << '\n';
            exit(0);
        }
        ll res = mx - a[v];
        res = mx - res * 2;
        return res;
    };
    if (dfs(root, -1) == 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}
