#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;
lint N, M;
struct edge{lint from, to, cost;};
vector<edge> es;
vector<lint> dist;

bool bellman_ford(int s) {
  for (int i = 0; i < N; i++) dist[i] = INF;
  dist[s] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      edge e = es[j];
      if (dist[e.from] == INF) continue;
      if (dist[e.to] > dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;
        if (i == N - 1 && e.to == N - 1)
          return true;
      }
    }
  }
  return false;
}

signed main(){
	cin >> N >> M;
	dist.resize(N);
	for(int i = 0; i < M; i++){
		lint a, b, c; cin >> a >> b >> c; 
		es.push_back(edge{a - 1, b - 1, -c}); 
	}
	if(bellman_ford(0)) cout << "inf" << endl;
	else cout << -dist[N - 1] << endl;
}