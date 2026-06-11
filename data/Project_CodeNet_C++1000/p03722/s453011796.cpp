#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge {
    ll from;
    ll to;
    ll cost;
};

using Edges = vector<Edge>;
const ll INF = 1LL << 60;

void bellman_ford(const Edges &Es, int V, int s, vector<ll> &dist) {
    dist.resize(V,INF);
    dist[0] = 0;
    int cnt = 0;
    while(cnt < 3*V) {
        for(auto e : Es) {
            if(dist[e.from] == INF) continue;
            if(dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                //負の閉路に含まれる頂点の距離を-INFとしてさらにn回以上伝播させる
                if(cnt == V-1) dist[e.to] = -INF;
            };
        }
        cnt++;
    }
}


int main()
{
    int n,m;
    cin >> n >> m;
    Edges Es(m);
    rep(i,m) {
        cin >> Es[i].from >> Es[i].to >> Es[i].cost;
        Es[i].from--; Es[i].to--;
        Es[i].cost *= -1;
    }

    vector<ll> dist;
    bellman_ford(Es, n, 0, dist);
    if(dist[n-1] < -INF) cout << "inf" << endl;
    else cout << -dist[n-1] << endl;
    return 0;
}