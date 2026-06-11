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
bool vis[100005];
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
    cin >> str;
    int n;
    n = str.length();
    int i;
    bool flag = 0;
    for (i = n - 2; i >= 0; i--)
    {
        flag = 0;
        if ((i) % 2 == 0)
        {
            for (int j = 0; j < i / 2; j++)
            {
                if (str[j] != str[j + (i / 2)])
                    flag = 1;
            }
            if (flag == 0)
                break;
        }
    }
    cout << i << "\n";

    return 0;
}
