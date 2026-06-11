#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll INF = 1e15;

struct edge {
  int u, v, cost;
};

ll dist[1010];

int main() {
  int N, M;
  cin >> N >> M;
  vector<edge> edges(M);
  for (auto &e : edges) {
    cin >> e.u >> e.v >> e.cost;
    e.u--, e.v--;
    e.cost = -e.cost;
  }

  vector<ll> dist(N, INF);
  dist[0] = 0;
  for (int i = 0; i < 2 * N; i++) {
    for (auto e : edges) {
      if (dist[e.u] == INF) continue;
      if (dist[e.u] + e.cost < dist[e.v]) {
        dist[e.v] = dist[e.u] + e.cost;
        if (i >= N - 1) dist[e.v] = -INF;
      }
    }
  }
  if (dist[N - 1] == -INF)
    cout << "inf" << endl;
  else
    cout << -dist[N - 1] << endl;
}