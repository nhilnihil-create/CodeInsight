#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)

typedef long long ll;
using namespace std;
const int INF = 1<<29;
struct Edge
{
    int to;
    ll cost;
};
using Graph = vector<vector<Edge>>;

set<pair<int, int>> isUsed;

void dijkstra(const Graph &G, int s)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    vector<ll> d((int)G.size(), INF);
    vector<vector<int>> path((int)G.size());

    q.push({0, s});
    d[s] = 0;

    while (!q.empty())
    {
        auto cur = q.top();q.pop();
        ll cur_dist = cur.first;
        int v = cur.second;
        if (cur_dist > d[v]) continue;
        for (auto e : G[v])
        {
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                q.push({d[v] + e.cost, e.to});

                path[e.to].clear();
                path[e.to].pb(v);
            }
            else if (d[e.to] == d[v] + e.cost)
            {
                path[e.to].pb(v);
            }
        }
    }

    rep(v, (int)G.size())
    {
        for (auto u : path[v])
        {
            isUsed.insert(mp(min(u, v), max(u, v)));
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Graph G(n);

    rep(i, m)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].pb(Edge{b, c});
        G[b].pb(Edge{a, c});
    }

    //任意の点開始の最短経路を求める
    rep(i, n)
    {
        dijkstra(G, i);
    }
    cout << m - (int)isUsed.size() << endl;
 //   system("pause");
    return 0;
}