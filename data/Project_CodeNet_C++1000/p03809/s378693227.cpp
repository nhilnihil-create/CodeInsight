// Crt. 2019-12-09  20:29:14
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

int n, d[N];
int tot, fir[N], nxt[N << 1], to[N << 1];
long long a[N], f[N];

inline void addE(int u, int v) {
    nxt[++tot] = fir[u], fir[u] = tot, to[tot] = v;
}

void dfs(int u, int p) {
    if (d[u] == 1) return f[u] = a[u], void();
    long long tmp, sum = 0, mxv = 0;
    for (int i = fir[u], v; i; i = nxt[i]) {
        v = to[i];
        if (v == p) continue;
        dfs(v, u);
        sum += f[v];
        mxv = max(mxv, f[v]);
    }
    f[u] = 2 * a[u] - sum;
    tmp = (sum - a[u]) * 2;
    if (f[u] < 0 || tmp < 0) puts("NO"), exit(0);
    if (sum - mxv < tmp / 2) puts("NO"), exit(0);
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;

    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    for (int i = 1, u, v; i < n; ++i)
        scanf("%d%d", &u, &v),
        addE(u, v), addE(v, u),
        ++d[u], ++d[v];

    if (n == 2) return puts(a[1] == a[2] ? "YES" : "NO"), 0;

    int root = 1;
    while (d[root] == 1) ++root;

    dfs(root, 0);

    puts(f[root] ? "NO" : "YES");

    return 0;
}
