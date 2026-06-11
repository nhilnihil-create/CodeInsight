#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> ans(n), cnt(n, -1);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    int q;
    cin >> q;
    vector<int> v(q), d(q), c(q);
    rep(i, 0, q) {
        cin >> v[q - 1 - i] >> d[q - 1 - i] >> c[q - 1 - i];
        v[q - 1 - i]--;
    }
    rep(i, 0, q) {
        if (cnt[v[i]] >= d[i]) continue;
        queue<int> que;
        que.push(v[i]);
        int dep = d[i];
        while (!que.empty()) {
            for (int j = que.size(); j > 0; j--) {
                int k = que.front();
                que.pop();
                if (ans[k] == 0) ans[k] = c[i];
                cnt[k] = dep;
                if (dep) {
                    for (int to : g[k])
                        if (cnt[to] < dep - 1) {
                            que.push(to);
                        }
                }
            }
            if (dep == 0) break;
            dep--;
        }
    }
    rep(i, 0, n) cout << ans[i] << endl;
    return 0;
}