#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<bool, int>;
ll INF = 1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;
        d[u].push_back(v);
        d[v].push_back(u);
    }
    vector<int> color(n);
    ll one = 0;
    ll bip = 0;
    ll nbip = 0;
    ll bsize = 0;
    ll nbsize = 0;
    for(int i = 0; i < n; i++)
    {
        if(color[i] != 0) continue;
        if(!d[i].size())
        {
            one++;
            continue;
        }
        queue<int> que;
        que.push(i);
        color[i] = 1;
        bool flag = true;
        int size = 0;
        while(que.size())
        {
            size++;
            int v = que.front();
            que.pop();
            for(int nx : d[v])
            {
                if(color[nx] == color[v]) flag = false;
                if(color[nx] == 0)
                {
                    que.push(nx);
                    color[nx] = -color[v];
                }
            }
        }
        if(flag)
        {
            bsize += size;
            bip++;
        }
        else
        {
            nbsize += size;
            nbip++;
        }
    }
    ll ans = one * one;
    ans += nbip * nbip; // nbip * nbip
    ans += bip * bip * 2; // bip * bip
    ans += one * bsize * 2;
    ans += one * nbsize * 2;
    ans += nbip * bip * 2;
    cout << ans << endl;
}

