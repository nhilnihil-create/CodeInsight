#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

struct edge { int a, b, c; };

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) g[i][i] = 0;
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a][b] = g[b][a] = c;
        edges[i] = {a, b, c};
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int ans = m;
    for (auto &e: edges) {
        bool flag = false;
        for (int s = 0; s < n - 1; s++) {
            for (int t = s + 1; t < n; t++) {
                if (g[s][e.a] + e.c + g[e.b][t] == g[s][t] || g[s][e.b] + e.c + g[e.a][t] == g[s][t]) {
                    flag = true;
                }
            }
        }
        if (flag) ans--;
    }
    cout << ans << endl;
    return 0;
}
