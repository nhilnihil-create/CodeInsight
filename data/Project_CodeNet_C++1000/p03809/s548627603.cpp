/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100002;

int n;

ll a[N_MAX];

vector <int> edges[N_MAX];

int root;

bool ok = true;

ll dfs (int u, int parent = -1)
{
    if(edges[u].size() == 1)
        return a[u];
    ll sum = 0;
    ll mx = 0;
    for(int v : edges[u])
        if(v != parent)
        {
            ll up = dfs(v, u);
            sum += up;
            mx = max(mx, up);
        }
    ll maxPairs = (sum / 2 - max(0LL, mx - ((sum + 1) / 2)));
    if(sum - a[u] < 0)
        ok = false;
    if(sum - a[u] > maxPairs)
        ok = false;
    return a[u] * 2 - sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    if(n == 2)
    {
        if(a[1] == a[2])
            cout << "YES\n";
        else
            cout << "NO\n";
        return 0;
    }
    for(int i = 1; i <= n; i++)
        if((int)edges[i].size() > 1)
        {
            root = i;
            break;
        }
    if(dfs(root) == 0 && ok == true)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
