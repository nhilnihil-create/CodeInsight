#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, m, k, x[100001], a[100001], b[100001], to[100001], cir[100001], ans[100001];
bool vis[100001];
int main(int argc, char const *argv[])
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &x[i]);
        b[i] = x[i] - x[i - 1];
        to[i] = i;
    }
    scanf("%lld%lld", &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &a[i]);
        swap(to[a[i]], to[a[i] + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int cnt = 0;
            for (int j = i; !vis[j]; j = to[j])
            {
                cir[++cnt] = j;
                vis[j] = 1;
            }
            for (int j = 1; j <= cnt; j++)
            {
                ans[cir[j]] = b[cir[(j + k - 1) % cnt + 1]];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] += ans[i - 1];
        printf("%lld.0\n", ans[i]);
    }
    return 0;
}