#include <bits/stdc++.h>

void fill(std::vector<std::deque<int>>& g, std::vector<std::vector<int>>& dp, int v, int d, int i) {
    if (d < 0) return;
    for (int j = 0; j <= d; j++) if (dp[v][j] < 0) dp[v][j] = i;
    if (!d) return;
    for (auto adj : g[v]) {
        if (dp[adj][d - 1] < 0) fill(g, dp, adj, d - 1, i);
    }
}

int main() {
    long long n, m, q;
    std::cin >> n >> m;
    std::vector<std::deque<int>> g(n);
    for (int i = 0; i < m; i++) {
        int p, q;
        std::cin >> p >> q;
        p--; q--;
        g[p].push_back(q);
        g[q].push_back(p);
    }

    std::cin >> q;
    std::vector<std::vector<int>> dp(n, std::vector<int>(11, -1));
    std::vector<int> v(q), d(q), c(q);
    for (int i = q - 1; i >= 0; i--) {
        std::cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }

    for (int i = 0; i < q; i++) fill(g, dp, v[i], d[i], i);
    for (int i = 0; i < n; i++) std::cout << (dp[i][0] < 0 ? 0 : c[dp[i][0]]) << std::endl;

    return 0;
}