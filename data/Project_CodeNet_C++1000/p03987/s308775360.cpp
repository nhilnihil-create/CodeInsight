#include <bits/stdc++.h>
#define N      200010
#define int    long long
using namespace std;
int n;
int a[N] = {};
int read()
{
    int  s = 0, w = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-')
        c = getchar();
    if (c == '-')
        w = -1, c = getchar();
    while (c <= '9' && c >= '0')
        s = (s << 3) + (s << 1) + c - '0', c = getchar();
    return s * w;
}
int pre[N] = {}, suf[N] = {};
int q[N << 1] = {}, h = 1, t = 0;
void push1(int x)
{
    while (h <= t && a[q[t]] >= a[x])
        suf[q[t]] = x - 1, --t;
    q[++t] = x;
}
void push2(int x)
{
    while (h <= t && a[q[t]] >= a[x])
        pre[q[t]] = x + 1, --t;
    q[++t] = x;
}
signed main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read(), pre[i] = 1, suf[i] = n;
    for (int i = 1; i <= n; ++i)
        push1(i);
    h = 1; t = 0;
    for (int i = n; i >= 1; --i)
        push2(i);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += (i - pre[i] + 1) * (suf[i] - i + 1) * a[i];
    }
    printf("%lld\n", sum);
    return 0;
}
