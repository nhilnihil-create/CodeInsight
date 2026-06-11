#include "bits/stdc++.h"

using namespace std;

vector<int> g[100010];

int dfs(int v, int p = 0)
{
    int r = 0;
    for (int nv : g[v])
    {
        if (nv == p)
            continue;
        r ^= dfs(nv, v) + 1;
    }
    return r;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int grundy = 0;
    for (int v : g[0])
    {
        grundy ^= dfs(v) + 1;
    }
    cout << (grundy ? "Alice" : "Bob") << endl;
}

int main()
{
    solve();
    return 0;
}
