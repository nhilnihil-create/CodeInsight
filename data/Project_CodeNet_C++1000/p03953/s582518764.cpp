#include <cstdio>
#include <algorithm>
#define maxn 100005

using namespace std;

inline long long read()
{
    long long x = 0;
    int f = 1;
    char ch = getchar();
    for(; ch < '0' || ch > '9'; ch = getchar())
        if(ch == '-')
            f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + (long long)ch - '0';
    return (long long)x * f;
}

int n, m, f[60][maxn];
long long k, er[60], p[maxn], d[maxn], a[maxn], b[maxn];

int getans(int x)
{
    for(register int i = 59; i >= 0; i -= 1)
        if(k & er[i])
            x = f[i][x];
    return x;
}

int main()
{
    int r;
    n = read();
    for(register int i = 1; i <= n; i += 1)
        p[i] = read(), d[i] = p[i] - p[i-1];
    m = read();
    k = read();
    for(register int i = 1; i <= n; i += 1)
        a[i] = i;
    for(register int i = 1; i <= m; i += 1)
        r = read(), swap(a[r], a[r+1]);
    for(register int i = 1; i <= n; i += 1)
        f[0][a[i]] = i;
    er[0] = 1;
    for(register int i = 1; i <= 59; i += 1)
        er[i] = er[i-1] * 2;
    for(register int i = 1; i <= 59; i += 1)
        for(register int j = 1; j <= n; j += 1)
            f[i][j] = f[i-1][f[i-1][j]];
    for(register int i = 1; i <= n; i += 1)
        a[i] = getans(i);
    for(register int i = 1; i <= n; i += 1)
        b[a[i]] = i;
    for(register int i = 1; i <= n; i += 1)
        p[i] = p[i-1] + d[b[i]], printf("%lld.0\n", p[i]);
    return 0;
}