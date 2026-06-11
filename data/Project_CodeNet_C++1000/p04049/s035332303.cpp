#include<bits/stdc++.h>

using namespace std;

int const maxn = 2005;
int n, k, ans;
int dp[maxn][maxn];
int pref_min[maxn][maxn];
int sz[maxn];
vector < int > g[maxn];

void dfs(int v, int p) {
    sz[v] = 1;
    int child = 0;
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        child++;
        sz[v] += sz[u];
    }
    dp[v][0] = sz[v];
    if (child == 0) {
        dp[v][1] = 0;
    }
    for (int h = 1; h <= k + 1; ++h) {
        int cur = min(h - 1, k + 1 - h), sum = 0;
        for (auto u : g[v]) {
            if (u == p) continue;
            sum += pref_min[u][cur];
        }
        for (auto u : g[v]) {
            if (u == p) continue;
            dp[v][h] = min(dp[v][h], sum - pref_min[u][cur] + dp[u][h - 1]);
        }
        ans = min(ans, dp[v][h] + n - sz[v]);
    }
    pref_min[v][0] = dp[v][0];
    for (int i = 1; i <= k + 1; ++i) pref_min[v][i] = min(pref_min[v][i - 1], dp[v][i]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= k + 1; ++j) dp[i][j] = n + 1, pref_min[i][j] = n + 1;
    ans = n;
    dfs(1, 0);
    //cout << dp[2][2] << endl;
    cout << ans << '\n';
    return 0;
}

