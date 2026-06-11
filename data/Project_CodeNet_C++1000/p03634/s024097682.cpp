#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

struct edge {Int to, cost;};
const int MAX_V = 110000;
vector<edge> G[MAX_V];
Int d[MAX_V];
int V;

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, LINF);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

Int ans[110000];

int main() {
    cin >> V;
    rep(i,V-1) {
        Int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        edge e1 = {u, c};
        G[v].push_back(e1);
        edge e2 = {v, c};
        G[u].push_back(e2);
    }
    int q, k;
    cin >> q >> k;
    k--;
    dijkstra(k);
    rep(i,q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ans[i] = d[x] + d[y];
    }
    rep(i,q) cout << ans[i] << endl;
}