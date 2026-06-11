#include <functional>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q; cin >> q;
    int v[q], d[q], c[q];
    for (int i = 0; i < q; i++) cin >> v[i] >> d[i] >> c[i];
    int col[n][11], time[n][11];
    memset(col, 0, sizeof(col));
    memset(time, 0, sizeof(time));
    function<void(int, int, int, int)> dfs = [&](int v, int d, int c, int t) {
        col[v][d] = c;
        time[v][d] = t;
        if (d == 0) return;
        for (int u : adj[v]) if (col[u][d-1] == 0) dfs(u, d-1, c, t);
    };
    for (int i = q-1; i >= 0; i--)
        if (col[v[i]-1][d[i]] == 0) dfs(v[i]-1, d[i], c[i], i);
    for (int i = 0; i < n; i++) {
        int ans = 0, t = -1;
        for (int d = 0; d <= 10; d++)
            if (t < time[i][d] && col[i][d] > 0) {
                t = time[i][d];
                ans = col[i][d];
            }
        cout << ans << endl;
    }
}
