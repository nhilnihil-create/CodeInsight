#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n == 2)
    {
        if(a[0] == a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    bool ans = true;
    function<ll(int, int)> dfs = [&](int v, int pre)
    {
        if(g[v].size() == 1) return a[v];
        ll sum = 0;
        int ma = 0;
        for(int nx : g[v])
        {
            if(nx == pre) continue;
            int cur = dfs(nx, v);
            sum += cur;
            ma = max(ma, cur);
        }
        if(2 * a[v] < sum || ma > a[v] || a[v] > sum) ans = false;
        return 2 * a[v] - sum;
    };
    int res = -1;
    for(int i = 0; i < n; i++)
    {
        if(g[i].size() > 1)
        {
            res = dfs(i, -1);
            break;
        }
    }
    if(ans && res == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
