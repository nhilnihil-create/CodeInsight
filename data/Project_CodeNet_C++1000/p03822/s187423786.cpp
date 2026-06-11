#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n+1);
    for(int i = 2; i <= n; i++)
    {
        int d;
        cin >> d;
        a[d].push_back(i);
    }
    vector<int> dp(n+1);

    function<int(int)> dfs = [&](int v)
    {
        if(a[v].empty())
        {
          return dp[v] = 0;
        }
        vector<int> tmp;
        for(int child : a[v])
        {
            tmp.push_back(dfs(child));
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        int high = 0;
        for(int i = 0; i < a[v].size(); i++)
        {
            high = max(high, tmp[i] + i+1);
        }
        return dp[v] = high;
    };
    dfs(1);
    cout << dp[1] << endl;
}
