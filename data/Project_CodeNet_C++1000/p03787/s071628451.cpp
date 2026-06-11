#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
typedef long long ll;

int col[MAXN];
vector<int> g[MAXN];

bool dfs(int v, int c)
{
    col[v] = c;
    bool flag = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!col[to]) flag &= dfs(to, 3-c);
        else if (col[to] != 3-c) flag = false;
    }
    return flag;
}


int main()
{
    ll n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll iso = 0, bip = 0, othr = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!col[i])
        {
            if (g[i].size() == 0) iso++;
            else if (dfs(i, 1)) bip++;
            else othr++;
        }
    }

    cout << (n-iso)*iso + iso*n + 2*bip*bip + 2*othr*bip + othr*othr;

    return 0;
}

