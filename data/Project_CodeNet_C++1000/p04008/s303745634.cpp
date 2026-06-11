#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()

int n, k;
int a[500000];
int ans = 0;
vector<int> graph[500000];
int dist[500000];
int go[33][500000];
int marked[500000];

void dfs(int v, int p, int d)
{
    go[0][v] = p;
    dist[v] = d;
    for (auto u : graph[v]) dfs(u, v, d + 1);
}

int Go(int op, int v)
{
    for (int j = 30; j >= 0; j--)
    {
        if (op >= (1 << j))
        {
            op -= (1 << j);
            v = go[j][v];
        }
    }
    return v;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1] != 1)
    {
        a[1] = 1;
        ans++;
    }
    for (int i = 2; i <= n; i++)
    {
        graph[a[i]].push_back(i);
    }
    dfs(1, 1, 0);
    for (int j = 1; j <= 30; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            go[j][i] = go[j - 1][go[j - 1][i]];
        }
    }
    set<pair<int, int>, greater<pair<int, int> > > ss;
    for (int i = 1; i <= n; i++) ss.insert({dist[i], i});
    while (ss.size())
    {
        pair<int, int> it = *ss.begin();
        ss.erase(ss.begin());
        if (Go(k, it.second) == 1) continue;
        int g = Go(k - 1, it.second);
        ans++;
        marked[g] = 1;
        vector<int> kek = {g};
        for (int i = 0; i < kek.size(); i++)
        {
            ss.erase({dist[kek[i]], kek[i]});
            for (auto u : graph[kek[i]])
            {
                if (marked[u] == 0)
                {
                    kek.push_back(u);
                    marked[u] = 1;
                }
            }
        }
    }
    cout << ans;
}
