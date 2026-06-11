#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

int N;
vector<int> dp(100000, INF);
vector<vector<int>> g(100000);

int dfs(int cur, int pre)
{
    if (g[cur].size() == 0)
    {
        return dp[cur] = 0;
    }
    vector<int> dis;
    for (auto v : g[cur])
    {
        if (v == pre)
            continue;
        dis.push_back(dfs(v, cur));
    }
    sort(dis.rbegin(), dis.rend());
    int res = 0;
    for (int i = 1; i <= (int)dis.size(); i++)
    {
        res = max(res, dis[i-1] + i);
    }
    return dp[cur] = res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a;
        cin >> a;
        a--;
        g[a].push_back(i);
    }
    cout << dfs(0, -1) << endl;
}
