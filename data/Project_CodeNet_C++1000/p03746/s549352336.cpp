#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

#define MAX_N 100010

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    bool vis[MAX_N];
    rep(i, n) vis[i] = false;
    vector<int> G[MAX_N];
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vis[0] = true;
    vector<int> nxt(n, -1);
    int l = 0, r = 0, len = 1;
    while (1)
    {
        bool ok = true;
        rep(i, G[l].size()) if (!vis[G[l][i]]) ok = false;
        rep(i, G[r].size()) if (!vis[G[r][i]]) ok = false;
        if (ok)
        {
            int now = l;
            cout << len << endl;
            cout << l + 1 << " ";
            while (now != r)
            {
                cout << nxt[now] + 1 << " ";
                now = nxt[now];
            }
            return 0;
        }
        rep(i, G[l].size()) if (!vis[G[l][i]])
        {
            nxt[G[l][i]] = l;
            vis[G[l][i]] = true;
            l = G[l][i];
            len++;
            break;
        }
        rep(i, G[r].size()) if (!vis[G[r][i]])
        {
            nxt[r] = G[r][i];
            vis[G[r][i]] = true;
            r = G[r][i];
            len++;
            break;
        }
    }
}