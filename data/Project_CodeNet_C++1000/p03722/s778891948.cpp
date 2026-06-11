#include <bits/stdc++.h>
using namespace std;
#define int long long
int inf = 10e17;
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
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int n;
    cin >> n;
    int m;
    cin >> m;
    int dis[n + 1];
    int dis1[n + 1];
    vector<pair<int, pair<int, int>>> vec, vec1;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // vec.push_back({c, {a, b}});
        vec1.push_back({-c, {a, b}});
        // dis[i + 1] = inf;
        //dis1[i + 1] = inf;
    }
    for (int i = 1; i <= n; i++)
        dis[i] = inf;

    dis[1] = 0;
    belman(n, m, vec1, dis);
    for (int i = 0; i < n; i++)
        dis1[i + 1] = dis[i + 1];
    belman(n, m, vec1, dis);
    bool flag = 0;
    //    // for (int i = 1; i <= n; i++)
    //     {
    //         cout << dis[i] << " " << dis1[i] << "\n";
    //     }
    if (dis[n] != dis1[n])
    {
        cout << "inf"
             << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
        dis[i] = inf;
    dis[1] = 0;

    belman(n, m, vec1, dis);
    cout << -1 * dis[n] << "\n";

    return 0;
}
