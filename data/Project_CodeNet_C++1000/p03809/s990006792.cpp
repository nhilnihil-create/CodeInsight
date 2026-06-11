#include<bits/stdc++.h>

using namespace std;

#define int long long

const int   N   = 1e5 + 1;

vector<int> g[N];
int n, R, a[N];
int f[N], p[N];

void dfs(int u,int pu)  {
    for(int v : g[u])
        if(v != pu) {
            p[v] = u;
            dfs(v,u);
            f[u] -= f[v];
        }
    if(f[u] < 0)    {
        puts("NO");
        exit(0);
    }
}

signed main()   {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1 ; i <= n ; ++i)
        cin >> a[i];

    for(int i = 1 ; i <  n ; ++i)   {
        int x, y;   cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 1 ; i <= n ; ++i)
        f[i] = (2 - (g[i].size() < 2)) * a[i];

    dfs(1,0);

    if(f[1])    return 0 * puts("NO");

    for(int i = 1 ; i <= n ; ++i)   {
        if(g[i].size() < 2) continue;
        int sum = f[i];
        for(int v : g[i])
            if(v != p[i])
                sum += f[v];
        if(f[i] > sum / 2)  return 0 * puts("NO");
        for(int v : g[i])
            if(v != p[i] && f[v] > sum / 2)
                return 0 * puts("NO");
    }
    puts("YES");
}
