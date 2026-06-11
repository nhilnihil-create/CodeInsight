#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 100005;

int n, K, fa[MAXN][20], ans, dfn[MAXN], sz[MAXN], dep[MAXN], cnt;
int tot, fir[MAXN], nxt[MAXN], to[MAXN];

namespace bit {
    int sum[MAXN];
    void add(int pos, int w) {
        while (pos <= n)
            sum[pos] += w, pos += pos & (-pos);
    }
    int ask(int pos) {
        int res = 0;
        while (pos)
            res += sum[pos], pos -= pos & (-pos);
        return res;
    }
}

using bit::add;
using bit::ask;

inline void addEdge(int u, int v) {
    nxt[++tot] = fir[u], fir[u] = tot, to[tot] = v;
}

void dfs(int u) {
    dep[u] = dep[fa[u][0]] + 1, dfn[u] = ++cnt, sz[u] = 1;
    for (int k = 0; k < 18; ++k)
        fa[u][k + 1] = fa[fa[u][k]][k];
    for (int i = fir[u]; i; i = nxt[i])
        dfs(to[i]), sz[u] += sz[to[i]];
}

struct cmp {
    bool operator()(const int &x, const int &y) const {
        return dep[x] < dep[y];
    }
};

priority_queue<int, vector<int>, cmp> q;

int jump(int u, int w) {
    for (int i = 18; i >= 0; --i)
        if ((w >> i) & 1) u = fa[u][i];
    return u;
}

int main() {
    cin >> n >> K;
    for (int i = 1; i <= n; ++i)
        scanf("%d", fa[i]);

    if (fa[1][0] != 1) ++ans, fa[1][0] = 1;

    for (int i = 2; i <= n; ++i)
        addEdge(fa[i][0], i);

    dfs(1);

    for (int i = 2; i <= n; ++i)
        q.push(i);

    while (!q.empty()) {
        int u = q.top(); q.pop();
        if (ask(dfn[u]) || K >= dep[u]) continue;
        int anc = jump(u, K - 1);
        if (fa[anc][0] == 1) continue;
        add(dfn[anc], 1), add(dfn[anc] + sz[anc], -1), ++ans;
    }

    cout << ans << endl;

    return 0;
}
