#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
vector<int> t[MAXN + 5];
int dfs(int x, int depth, int fa)
{
    int ans = 1;
    if (depth > 0)
        for (auto i : t[x])
            if (i != fa)
                ans += dfs(i, depth - 1, x);
    return ans;
}
vector<pair<int, int>> edge;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
        edge.push_back(make_pair(a, b));
    }
    int ans = n;
    if (k % 2 == 0)
        for (int root = 1; root <= n; root++)
            ans = min(ans, n - dfs(root, k / 2, -1));
    else
        for (auto e : edge)
            ans = min(ans, n - dfs(e.first, k / 2, e.second) - dfs(e.second, k / 2, e.first));
    cout << ans;
}