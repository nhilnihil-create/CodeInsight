#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;
struct edge { ll to, cost; };

const int MAX_V =100000;
const ll INF = 1LL<<60;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep(i,G[v].size()) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int a, b, c, Q, K, x, y;
    cin >> V;
    rep(i, V - 1) {
        cin >> a >> b >> c;
        G[a - 1].push_back({b - 1, c});
        G[b - 1].push_back({a - 1, c});
    }
    cin >> Q >> K;
    dijkstra(K - 1);
    rep(i, Q) {
        cin >> x >> y;
        cout << d[x - 1] + d[y - 1] << "\n";
    }
}