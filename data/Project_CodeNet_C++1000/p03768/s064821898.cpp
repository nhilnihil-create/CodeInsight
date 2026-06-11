#include <bits/stdc++.h>


using namespace std;


const int MAXN = 100 * 1000 + 23, MAXD = 10 + 3;








int n, m, q, a[MAXN], c[MAXN], d[MAXN], r[MAXD][MAXN];
vector<int> g[MAXN];

void dfs(int, int, int);

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v), g[v].push_back(u);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
        cin >> a[q - i - 1] >> d[q - 1 - i] >> c[q - i - 1], a[q - i - 1]--;
    for (int i = 0; i < q; i++)
        dfs(a[i], d[i], c[i]);
    for (int i = 0; i < n; i++)
        cout << r[0][i] << '\n';
    return 0;
}
void dfs(int v, int d, int c) {
    if (d < 0 || r[d][v] != 0) return;
    else for (int i = d; ~i; i--) if (r[i][v] == 0) r[i][v] = c; else break;
    for (auto u : g[v]) dfs(u, d - 1, c);
}