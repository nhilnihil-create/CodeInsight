#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)

typedef long long LL;
typedef pair<LL, LL> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;
#define pow10(n) int(1e##n + n)

struct edge
{
    int to;
    LL cost;
};

LL d[pow10(5)];

void solve()
{
    int V;
    cin >> V;
    vector<vector<edge>> adj(V);
    REP0 (i, V - 1)
    {
        int a, b;
        LL c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back(edge{b, c});
        adj[b].push_back(edge{a, c});
        d[i] = LLINF;
    }
    int Q, K;
    cin >> Q >> K;
    K--;

    d[V - 1] = LLINF;
    d[K] = 0;

    // pair<mincost, vertex>
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push(pii(0, K));
    while (PQ.size())
    {
        pii p = PQ.top();
        PQ.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (auto e : adj[v])
        {
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                PQ.push(pii(d[e.to], e.to));
            }
        }
    }

    REP0 (i, Q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        std::cout << d[x] + d[y] << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
