#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, q, a[maxn];
bool mark[maxn][11];
vector<int> G[maxn];
vector<tuple<int, int, int>> Q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    scanf("%d", &q);
    for (int i = 1, v, d, c; i <= q; i++) {
        scanf("%d %d %d", &v, &d, &c);
        Q.push_back(make_tuple(v, d, c));
    }
    reverse(Q.begin(), Q.end());
    for (auto p : Q) {
        int v = get<0>(p), d = get<1>(p), c = get<2>(p);
        function<void(int, int)> dfs = [&](int v, int d) {
            if (mark[v][d]) return;
            mark[v][d] = 1;
            if (!d) { a[v] = c; return; }
            dfs(v, d - 1);
            for (int u : G[v]) dfs(u, d - 1);
        };
        dfs(v, d);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}