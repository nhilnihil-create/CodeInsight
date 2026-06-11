#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 35;

signed main () {
    int n, m;
    cin >> n >> m;
    int g[n + 1][n + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) 
            g[i][j] = inf;
        g[i][i] = 0;
    }
    int a[m], b[m], c[m];
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        g[a[i]][b[i]] = c[i];
        g[b[i]][a[i]] = c[i];
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
    int ans = m;
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (c[i] + g[j][a[i]] == g[j][b[i]]) {
                --ans;
                break;
            }
        }
    }
    cout << ans << '\n';
}
