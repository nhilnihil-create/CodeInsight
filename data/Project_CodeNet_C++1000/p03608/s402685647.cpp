#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 13;

signed main () {
    int n, m, r;
    cin >> n >> m >> r;
    vector < vector < int > > floyd(n + 1, vector < int > (n + 1, inf));
    vector < int > order(r);
    for (int i = 0; i < r; ++i)
        cin >> order[i];
    sort(order.begin(), order.end());
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        floyd[u][v] = min(w, floyd[u][v]); 
        floyd[v][u] = min(w, floyd[v][u]);
    }
    for (int i = 0; i <= n; ++i)
        floyd[i][i] = 0;
    for (int k = 0; k <= n; ++k) {
        for (int u = 0; u <= n; ++u) {
            for (int v = 0; v <= n; ++v)
                floyd[u][v] = min(floyd[u][v], floyd[u][k] + floyd[k][v]);
        }
    }
    int ans = inf;
    do {
        int res = 0;
        for (int i = 0; i < r - 1; ++i)
            res += floyd[order[i]][order[i + 1]];
        ans = min(res, ans);
    } while (next_permutation(order.begin(), order.end()));
    cout << ans << '\n';
}
