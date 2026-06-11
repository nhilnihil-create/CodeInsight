
#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e6 + 5;

inline ll read()
{
    ll w = 0;
    ll t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {if (ch == '-') t = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') { w = (w << 3) + (w << 1) + (ch ^ '0'); ch = getchar();}
    return w * t;
}
int n, m;
ll k;
ll a[maxn];
int vis[maxn], to[maxn], c[maxn];
ll ans[maxn];
int main()
{
    n = read();
    ll lst = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read() - lst;
        lst += a[i];
        to[i] = i;
    }
    m = read(), k = read();
    int input;
    for (int i = 1; i <= m; i++)
        input = read(), std::swap(to[input], to[input + 1]);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            int cnt = 0, j;
            for (j = i; !vis[j]; j = to[j])
                vis[j] = 1, c[++cnt] = j;
            for (j = 1; j <= cnt; j++)
                ans[c[j]] = a[c[(j + k - 1) % cnt + 1]];
        }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld.0\n", ans[i] += ans[i - 1]);
    }
    return 0;
}