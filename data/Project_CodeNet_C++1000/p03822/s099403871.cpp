#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;
#define prev prev55

long long n;
int a[500000];
vector<int> graph[600000];

int dp[600000];

void dfs2(int v)
{
    vector<int> kek;
    for (auto u : graph[v])
    {
        dfs2(u);
        kek.push_back(dp[u]);
    }
    sort(kek.begin(), kek.end());
    reverse(kek.begin(), kek.end());
    for (int i = 0; i < kek.size(); i++)
    {
        dp[v] = max(dp[v], kek[i] + i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        graph[a[i]].push_back(i);
    }
    dfs2(1);
    cout << dp[1];
}
