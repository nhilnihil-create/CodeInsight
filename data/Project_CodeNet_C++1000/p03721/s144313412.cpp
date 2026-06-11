#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        ind += vec[i].second;
        if (ind >= k)
        {
            cout << vec[i].first << "\n";
            break;
        }
    }
    return 0;
}
