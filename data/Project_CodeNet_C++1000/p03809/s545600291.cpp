#include <bits/stdc++.h>
using namespace std;
int read();

int n, root;
int a[200005], l[200005], r[200005];
vector<int> e[200005];
void add(int f, int t) { e[f].push_back(t), e[t].push_back(f); }
void dfs(int u, int fa) {
    if (e[u].size() == 1) return l[u] = r[u] = a[u], void();
    int mxl = 0, suml = 0, sumr = 0;
    for (int i = 0, v; i < e[u].size(); ++i)
        if ((v = e[u][i]) != fa)
            dfs(v, u), suml += l[v], sumr += r[v], mxl = max(mxl, l[v]);
    l[u] = max(0, 2 * a[u] - sumr), r[u] = min(2 * a[u] - sumr, a[u]);
    if (l[u] > r[u] || a[u] < mxl) puts("NO"), exit(0);
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    if (n == 2) return puts(a[1] == a[2] ? "YES" : "NO"), 0;
    for (int i = 1, u, v; i < n; ++i) u = read(), v = read(), add(u, v);
    for (int i = 1; i <= n; ++i)
        if (e[i].size() > 1) root = i;
    dfs(root, 0), puts(l[root] ? "NO" : "YES");
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
