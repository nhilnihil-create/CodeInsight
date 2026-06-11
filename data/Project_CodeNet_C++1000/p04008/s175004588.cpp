#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1;
int a[N], ans, k;
vector<int> g[N];
int dfs(int v, int pr = -1)
{
    int h = 0;
    for (int i : g[v])
    {
        h = max(dfs(i, v), h);
    }
    h++;
    if (v == 1)
        return 0;
    if (h == k)
    {
        if (pr != 1)
            ans++;
        return 0;
    }
    else
    {
        return h;
    }
}
signed main()
{
#ifdef home
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] != 1)
    {
        a[1] = 1;
        ans++;
    }
    for (int i = 2; i <= n; i++)
    {
        g[a[i]].push_back(i);
    }
    dfs(1);
    cout << ans;
}