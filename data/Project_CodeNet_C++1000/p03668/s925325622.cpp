#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dp(n, 0);
    function<void(int, int)> Dfs = [&](int x, int p) {
        for (int u : g[x]) {
            if (u == p) continue;
            Dfs(u, x);
            dp[x] ^= dp[u] + 1;
        }
    };

    Dfs(0, -1);
    if (dp[0]) puts("Alice");
    else puts("Bob");
}
