#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m;
deque<int> q;
bool vis[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    q.push_back(1), vis[1] = 1;
    while (1) {
        bool flag = 0;
        int x = q.front(), y = q.back();
        for (int u : G[x]) {
            if (!vis[u]) { vis[u] = flag = 1, q.push_front(u); break; }
        }
        if (flag) continue;
        for (int u : G[y]) {
            if (!vis[u]) { vis[u] = flag = 1, q.push_back(u); break; }
        }
        if (flag) continue;
        break;
    }
    printf("%d\n", q.size());
    for (int x : q) printf("%d ", x);
    return 0;
}