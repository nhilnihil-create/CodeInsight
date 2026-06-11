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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    int mn = k / 2;
    vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[i] = x;
        b[i] = y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    if (k == 1) {
        cout << n - 2 << '\n';
        return 0;
    }
    int ans = n;
    vector<int> depth;
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (depth[to] <= depth[v] + 1) {
                continue;
            }
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
    };
    if (k % 2 == 0) {
        for (int i = 0; i < n; i++) {
            depth = vector<int>(n, 1e9);
            depth[i] = 0;
            dfs(i, -1);
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (depth[j] <= mn) {
                    cnt++;
                }
            }
            ans = min(ans, n - cnt);
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            depth = vector<int>(n, 1e9);
            depth[a[i]] = 0;
            depth[b[i]] = 0;
            dfs(a[i], b[i]);
            dfs(b[i], a[i]);
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (depth[j] <= mn) {
                    cnt++;
                }
            }
            ans = min(ans, n - cnt);
        }
    }
    cout << ans << '\n';
    return 0;
}