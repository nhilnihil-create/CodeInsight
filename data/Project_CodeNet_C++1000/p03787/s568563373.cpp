#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> col(n);
    vector<int> vis(n);

    long long bip = 0, one = 0, oth = 0;
    bool ok;

    function<void(int)> is_bipartite = [&](int u) {
        vis[u] = 1;

        for (auto v : adj[u])
        {
            if (vis[v])
            {
                if (col[u] == col[v])
                    ok = false;
            }
            else
            {
                col[v] = col[u] ^ 1;
                is_bipartite(v);
            }
        }
    };

    for (int i = 0; i < n; ++i)
    {
        if (vis[i])
            continue;

        if (adj[i].empty())
        {
            one++;
            continue;
        }

        ok = true;
        is_bipartite(i);

        if (ok)
        {
            bip++;
        }
        else
        {
            oth++;
        }
    }

    long long answer = 2 * n * one - one * one;

    answer += (bip + oth) * (bip + oth) + bip * bip;

    cout << answer << endl;

    return 0;
}