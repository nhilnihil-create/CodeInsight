#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5+5;
typedef long long ll;

bool used[Nmax][2], ok;
int x, y, i, n, m, bip, nonbip, iso;
vector<int> v[Nmax];

void dfs(int node, int par)
{
    used[node][par] = 1;
    par ^= 1;
    if(used[node][par]) ok = 1;

    for(auto it : v[node])
        if(!used[it][par])
            dfs(it, par);
}

int main()
{
    //freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    for(i=1; i<=m; ++i)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(i=1; i<=n; ++i)
        if(v[i].empty()) ++iso;
            else if(!used[i][0] && !used[i][1])
            {
                ok = 0;
                dfs(i, 0);
                if(!ok) ++bip;
                    else ++nonbip;
            }

    cout << (ll)iso * (2*n-iso) + (ll) 2 * bip * (bip + nonbip) + (ll) nonbip * nonbip << '\n';

    return 0;
}
