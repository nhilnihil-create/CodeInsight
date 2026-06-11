#include <bits/stdc++.h>
using namespace std;
#define int long long
int inf = 10e17;
#define mod 1000000007
int findLowerBound(
    vector<pair<int, int>> &arr,
    pair<int, int> &p)
{

    auto low = lower_bound(arr.begin(),
                           arr.end(), p);

    return low - arr.begin();
}
int findUpperBound(
    vector<pair<int, int>> &arr,
    pair<int, int> &p)
{
    auto up = upper_bound(arr.begin(),
                          arr.end(), p);

    return up - arr.begin();
}
bool vis[200005];
vector<int> vec[100005];
int child[100005];
int div1[100005];
void dfs(int node)
{
    vis[node] = 1;
    for (int i = 0; i < vec[node].size(); i++)
    {
        if (!vis[vec[node][i]])
        {
            dfs(vec[node][i]);
            child[node] += child[vec[node][i]];
        }
    }
}
void belman(int n, int m, vector<pair<int, pair<int, int>>> vec, int dis[])
{
    for (int i = 0; i <= n + m - 1; i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            int u = vec[j].second.first;
            int v = vec[j].second.second;
            int w = vec[j].first;

            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
}
int fun(int a, int b)
{
    if (a > b)
        return 0;
    if (a == b)
        return 1;
    else
    {
        return fun(a + 1, b) + fun(a, b - a);
    }
}
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int j = 1;
    for (int i = 2; i < 1001; i++)
    {
        if (!vis[i * j])
        {
            while (i * j < 1001)
            {
                div1[i * j] = i;
                vis[i * j] = 1;
                j++;
            }
        }
        j = 1;
    }
    div1[1] = 1;
    // for (int i = 1; i < 20; i++)
    //   cout << div1[i] << "\n";
    int n, a, b;
    cin >> n >> a >> b;
    int dp[n];
    for (int i = 0; i < n; i++)
        cin >> dp[i];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += min((dp[i] - dp[i - 1]) * a, b);
    }
    cout << ans << "\n";

    return 0;
}
