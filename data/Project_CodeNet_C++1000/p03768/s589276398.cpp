#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
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
    vector<int> color(n);
    vector<int> infl(n, -1);
    function<void(int, int, int)> dfs = [&](int pos, int paint, int dis)
    {
        infl[pos] = dis;
        if(dis == 0) return;
        for(int next : g[pos])
        {
            if(next == pos) continue;
            if(color[next] == 0) color[next] = paint;
            if(infl[next] < dis-1) dfs(next, paint, dis-1);
        }
    };

    for(int i = q-1; i >= 0; i--)
    {
        int start = v[i];
        if(color[start] == 0) color[start] = c[i];
        if(infl[start] < d[i]) dfs(start, c[i], d[i]);
    }
    for(int i = 0; i < n; i++)
    {
        cout << color[i] << endl;
    }
}

