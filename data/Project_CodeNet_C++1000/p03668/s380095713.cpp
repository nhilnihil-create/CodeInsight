#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string, string>;
ll MOD = 1e9+7;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;y--;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    int size = d[0].size();
    function<int(int, int)> dfs = [&](int v, int pre)
    {
        int grundy = 0;
        for(int cand : d[v])
        {
            if(cand == pre) continue;
            grundy ^= dfs(cand, v) + 1;
        }
        return grundy;
    };
    int x = 0;
    for(int i = 0; i < size; i++)
    {
        int grundy = dfs(d[0][i], 0);
        x ^= grundy+1;
    }
    if(x != 0)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
}

