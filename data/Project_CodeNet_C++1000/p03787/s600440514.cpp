#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int mark[N], cnt[2], node, val;
vector <int> g[N];

void dfs(int v, int col = 1) {
    mark[v] = col, node++;
    for (int u : g[v]) {
        if (!mark[u]) dfs(u, 3 - col);
        else if (col == mark[u]) val = 0;
    }
    return ;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    long long ans = 0, res = 0;
    for (int i = 1; i <= n; i++) if (!mark[i]) {
        val = 1, node = 0, dfs(i);
        if (node == 1) {res++; continue ;}
        if (val == 1) ans += 4 * cnt[1] + 2 * cnt[0] + 2;
        else ans += 2 * (cnt[0] + cnt[1]) + 1;
        cnt[val]++;
    }
    cout << ans + 2 * n * res - res * res << "\n";
}
