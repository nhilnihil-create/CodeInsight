#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

#define INF 1LL << 60
#define MAX_V 100010

struct edge {
    ll to;
    ll cost;
};

// <最短距離, 頂点の番号>
using P = pair<ll, ll>;

ll V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;

        for(int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    V = N;
    for(int i = 0; i < N - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    ll Q, K;
    cin >> Q >> K;
    K--;
    dijkstra(K);
    for(int i = 0; i < Q; i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << d[x] + d[y] << "\n";
    }
    return 0;
}
