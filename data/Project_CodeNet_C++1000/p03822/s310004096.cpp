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
    vector<int> a(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i]--;
        g[i].emplace_back(a[i]);
        g[a[i]].emplace_back(i);
    }
    vector<int> ans(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        vector<int> ch;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
            ch.emplace_back(ans[to]);
        }
        sort(ch.rbegin(), ch.rend());
        for (int i = 0; i < ch.size(); i++) {
            ans[v] = max(ans[v], i + 1 + ch[i]);
        }
    };
    dfs(0, -1);
    cout << ans[0] << '\n';
    return 0;
}