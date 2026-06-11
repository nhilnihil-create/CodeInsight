#include "bits/stdc++.h"
#define MOD 1000000007
#define inf 0x3f3f3f3f3f3f3f3f
#define pi acos(-1.0)
#define ri register int
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
#define int long long
const int maxn = 1e5 + 10;
inline int Max(int a, int b) { return a > b ? a : b; }
inline int Min(int a, int b) { return a > b ? b : a; }
namespace FastIO {
inline int read()
{
    int f = 1, r = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') {
            f = -1;
        }
        c = getchar();
    }
    while (isdigit(c)) {
        r = 10 * r + c - '0';
        c = getchar();
    }
    return f * r;
}
inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline void writesp(int x) { write(x), putchar(' '); }
inline void writeln(int x) { write(x), puts(""); }
};
using namespace FastIO;
int tot, ver[maxn << 1], next[maxn << 1], head[maxn], N, K, depth[maxn], ans;
inline void add(int u, int v) { ver[++tot] = v, next[tot] = head[u], head[u] = tot; }
inline void dfs(int u, int fa)
{
    depth[u] = 1;
    for (ri i = head[u]; i; i = next[i]) {
        if (ver[i] == fa) {
            continue;
        }
        dfs(ver[i], u);
        if (depth[ver[i]] == K && u != 1) {
            ans++;
            continue;
        }
        depth[u] = Max(depth[ver[i]] + 1, depth[u]);
    }
}
signed main()
{
    //freopen("C:\Users\hjw\Downloads\testdata (4).in", "r", stdin);
    N = read(), K = read();
    for (ri i = 1; i <= N; ++i) {
        int dst = read();
        if (i == 1) {
            if (dst != 1)
                ++ans;
            continue;
        }
        add(i, dst), add(dst, i);
    }
    dfs(1, 0);
    writeln(ans);
    return 0;
}