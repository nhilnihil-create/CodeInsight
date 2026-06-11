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
    int ans = 0;
    vector<int> a(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (i) {
            g[a[i]].emplace_back(i);
        }
    }
    if (a[0]) {
        a[0] = 0;
        ans++;
    }
    vector<int> depth(n), mx(n);
    function<void(int)> dfs = [&](int v) {
        mx[v] = depth[v];
        for (int to : g[v]) {
            depth[to] = depth[v] + 1;
            dfs(to);
            mx[v] = max(mx[v], mx[to]);
        }
        if (mx[v] - depth[v] >= k - 1 && depth[v] > 1) {
            mx[v] = depth[v] - 1;
            ans++;
            debug(v);
        }
    };
    dfs(0);
    cout << ans << '\n';
    return 0;
}
