#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e16)

struct Edge {
  ll from, to, cost;
  Edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
};
vector<Edge> edges;
vi dist;                            // 最短距離
bool bellman_ford(int nV, int s) {  // nVは頂点数、sは開始頂点
  dist = vi(nV, INF);
  dist[s] = 0;                        // 開始点の距離は0
  for (int i = 0; i < nV - 1; i++) {  // 負の閉路がない場合、nV回未満で更新が終わる
    for (Edge e : edges) {
      if (dist[e.to] > dist[e.from] + e.cost) {  // 距離更新
        dist[e.to] = dist[e.from] + e.cost;
        // if (i == nV - 1) return true;  // nV回目にも更新があるなら負の閉路が存在
      }
    }
  }
  return false;
}

int main() {
  ll N;
  cin >> N;
  ll M;
  cin >> M;
  for (ll i = 0; i < M; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    edges.push_back(Edge(a - 1, b - 1, -c));
  }

  bellman_ford(N, 0);

  bool f = false;
  for (int i = 0; i < N; i++) {
    for (Edge e : edges) {
      if (dist[e.to] > dist[e.from] + e.cost) {  // 距離更新
        dist[e.to] = dist[e.from] + e.cost;
        if (e.to == N - 1) f = true;  // nV回目にも更新があるなら負の閉路が存在
      }
    }
  }
  
  if (f) {
    cout << "inf" << endl;
    return 0;
  }

  ll ans = -dist[N - 1];
  cout << ans << endl;
}
