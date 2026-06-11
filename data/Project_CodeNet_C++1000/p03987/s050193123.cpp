#include "bits/stdc++.h"
#define MOD 1000000007
#define inf 0x3f3f3f3f3f3f3f3f
#define pi acos(-1.0)
#define ri register int
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
#define int long long
const int maxn = 2e5 + 10;
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
int arr[maxn], N, left[maxn], right[maxn], stk[maxn], top;
signed main()
{
    //freopen("C:\Users\hjw\Downloads\testdata (4).in", "r", stdin);
    N = read();
    for (ri i = 1; i <= N; ++i)
        arr[i] = read();
    for (ri i = 1; i <= N; ++i) {
        while (top && arr[stk[top]] >= arr[i]) {
            --top;
        }
        left[i] = stk[top] + 1;
        stk[++top] = i;
    }
    stk[0] = N + 1, top = 0;
    for (ri i = N; i >= 1; --i) {
        while (top && arr[stk[top]] >= arr[i]) {
            --top;
        }
        right[i] = stk[top] - 1;
        stk[++top] = i;
    }
    int ans = 0;
    for (ri i = 1; i <= N; ++i) {
        ans += (i - left[i] + 1) * arr[i] * (right[i] - i + 1);
    }
    writeln(ans);
    return 0;
}