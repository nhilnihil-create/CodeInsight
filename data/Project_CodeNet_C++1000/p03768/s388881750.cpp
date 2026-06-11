#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<int> v(q);
    vector<int> d(q);
    vector<int> c(q);
    for(int i = 0; i < q; i++)
    {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    vector<int> dis(n, -1);
    vector<int> color(n, 0);
    function<void(int, int, int)> dfs = [&](int v, int d, int c)
    {
        if(color[v] == 0) color[v] = c;
        dis[v] = d;
        if(d == 0) return;
        d--;
        for(int nx : g[v])
        {
            if(dis[nx] < d) dfs(nx, d, c);
        }
    };
    for(int i = q-1; i >= 0; i--)
    {
        if(dis[v[i]] < d[i]) dfs(v[i], d[i], c[i]);
    }
    for(int col : color)
    {
        cout << col << endl;
    }
}
