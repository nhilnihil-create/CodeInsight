#include "bits/stdc++.h"
#define MOD 1000000007
#define inf 0x3f3f3f3f3f3f3f3f
#define pi acos(-1.0)
#define ri register int
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
#define int long long
const int maxn = 2e3 + 10;
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
int N, X, arr[maxn], seg[maxn << 2];
struct Node {
    int base, transe;
} nodes[maxn];
inline void build(int l, int r, int cur)
{
    if (l == r) {
        seg[cur] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, cur << 1), build(mid + 1, r, cur << 1 | 1);
    seg[cur] = Min(seg[cur << 1], seg[cur << 1 | 1]);
}
inline int query(int l, int r, int L, int R, int cur)
{
    if (l >= L && r <= R) {
        return seg[cur];
    }
    int mn = inf, mid = (l + r) >> 1;
    if (mid >= L) {
        mn = query(l, mid, L, R, cur << 1);
    }
    if (mid < R) {
        mn = Min(mn, query(mid + 1, r, L, R, cur << 1 | 1));
    }
    return mn;
}
signed main()
{
    //freopen("C:\Users\hjw\Downloads\testdata (4).in", "r", stdin);
    N = read(), X = read();
    for (ri i = 1; i <= N; ++i) {
        arr[i] = read();
    }
    build(1, N, 1);
    int ans = inf;
    for (ri t = 0; t <= N; ++t) {
        int sum = t * X;
        if (sum > ans)
            break;
        for (ri i = 1; i <= N; ++i) {
            int left = i - t, right = i, mn = inf;
            if (left < 1) {
                mn = Min(mn, query(1, N, 1, right, 1));
                mn = Min(mn, query(1, N, N + i - t, N, 1));
            } else {
                mn = query(1, N, left, right, 1);
            }
            sum += mn;
        }
        ans = Min(ans, sum);
    }
    writeln(ans);
    return 0;
}