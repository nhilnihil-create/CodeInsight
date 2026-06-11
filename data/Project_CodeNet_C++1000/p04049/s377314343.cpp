#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back

const int MAXN = 2009;
vector<int> g[MAXN];
int n, k;

int dfs(int v, int pr, int len, int cur)
{
    int ans = 0;
    if (cur > len)
        ans++;
    for (int to : g[v])
    {
        if (to != pr)
            ans += dfs(to, v, len, cur + 1);
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans = n - 1;
    for (int i = 0; i < n; i++)
        ans = min(ans, dfs(i, -1, k / 2, 0));
    for (int i = 0; i < n; i++)
    {
        for (int to : g[i])
            ans = min(ans, dfs(i, to, (k - 1) / 2, 0) + dfs(to, i, (k - 1) / 2, 0));
    }
    cout << ans;
}
