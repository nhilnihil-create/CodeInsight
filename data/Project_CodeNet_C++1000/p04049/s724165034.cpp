#include "bits/stdc++.h"
#define MOD (1e9+7)
#define inf 0x3f3f3f3f3f3f3f3f
#define pi acos(-1.0)
#define ri register int
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
#define int long long
const int maxn = 1e4 + 10;
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
int N, K, tot, ver[maxn << 1], next[maxn << 1], head[maxn], dis[maxn], disa[maxn], disb[maxn];
inline void add(int u, int v)
{
    ver[++tot] = v, next[tot] = head[u], head[u] = tot;
}
void dfs(int u, int fa)
{
    dis[u] = dis[fa] + 1;
    for (ri i = head[u]; i; i = next[i]) {
        if (ver[i] == fa)
            continue;
        dfs(ver[i], u);
    }
}

inline int work1()
{
    int ans = inf;
    for (ri i = 1; i <= N; ++i) {
        dfs(i, 0);
        int num = 0;
        for (ri j = 1; j <= N; ++j) {
            int tmp = dis[j] - dis[i];
            if (tmp > K / 2) {
                ++num;
            }
        }
        ans = Min(ans, num);
    }
    return ans;
}
inline int work2()
{
    int ans = inf;
    for (ri i = 1; i <= N; ++i) {
        for (ri j = head[i]; j; j = next[j]) {
            int v = ver[j], u = i, num = 0;
            dfs(u, 0);
            memcpy(disa, dis, sizeof(dis));
            dfs(v, 0);
            memcpy(disb, dis, sizeof(dis));
            for (ri k = 1; k <= N; ++k) {
                int d1 = disa[k] - 1, d2 = disb[k] - 1;
                int mn = Min(d1, d2);
                if (mn > (K - 1) / 2) {
                    ++num;
                }
            }
            ans = Min(ans, num);
        }
    }
    return ans;
}
signed main()
{
    //freopen("C:\Users\hjw\Downloads\testdata (4).in", "r", stdin);
    N = read(), K = read();
    for (ri i = 1; i < N; ++i) {
        int u = read(), v = read();
        add(u, v), add(v, u);
    }
    int q;
    if (K & 1) {
        q = work2();
    } else {
        q = work1();
    }
    writeln(q);
    return 0;
}