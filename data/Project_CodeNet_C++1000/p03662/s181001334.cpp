#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100000
#define INF 1000000000000000
#define int long long
typedef pair<int, int> P; //firstは最短距離,secondは頂点の番号
struct edge
{
    long long to, cost;
};
struct graph
{
    int V;                  //頂点数
    vector<vector<edge>> G; //頂点sからの最短距離
    vector<long long> d;
    graph(int n)
    {
        init(n);
    }
    void init(int n)
    {
        V = n;
        G.resize(V);
        d.resize(V);
        for (int i = 0; i < V; i++)
        {
            d[i] = INF;
        }
    }
    void add_edge(int s, int t, long long cost)
    {
        edge e;
        e.to = t;      //行き先
        e.cost = cost; //cost
        G[s].push_back(e);
    }
    void dijkstra(int s)
    {
        for (int i = 0; i < V; i++)
        {
            d[i] = INF;
        }
        d[s] = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(P(0, s));
        while (!que.empty())
        {
            P p = que.top();
            que.pop();
            long long v = p.second;
            if (d[v] < p.first)
                continue;
            for (auto e : G[v])
            {
                if (d[e.to] > d[v] + e.cost)
                {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }
};
main()
{
    int n;
    cin >> n;
    graph G1(n);
    graph G2(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G1.add_edge(a, b, 1);
        G1.add_edge(b, a, 1);
        G2.add_edge(a, b, 1);
        G2.add_edge(b, a, 1);
    }
    G1.dijkstra(0);
    G2.dijkstra(n - 1);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (G1.d[i] <= G2.d[i])
        {
            cnt++;
        }
    }
    if (cnt == n - cnt)
        cout << "Snuke" << endl;
    else if (cnt > n - cnt)
        cout << "Fennec" << endl;
    else
        cout << "Snuke" << endl;
}
