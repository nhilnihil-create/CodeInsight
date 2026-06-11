#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

const int maxn = 2010;
int n, K, ans, d[maxn][maxn];
vector<int> G[maxn];
queue<int> q;
vector<int> V;

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++) {
        q.push(i), d[i][i] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (i == 1) V.push_back(v);
            for (int u : G[v]) if (!~d[i][u]) {
                q.push(u), d[i][u] = d[i][v] + 1;
            }
        }
    }
    for (int i = 0; i < V.size(); i++) {
        int cur = 1;
        for (int j = 0; j < i; j++) {
            if (d[V[i]][V[j]] <= K) cur++;
        }
        ans = max(ans, cur);
    }
    printf("%d\n", n - ans);
    return 0;
}