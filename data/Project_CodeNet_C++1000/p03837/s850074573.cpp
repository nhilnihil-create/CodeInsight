#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

int INF = 1e7;
int n, m;
vector<P> edge[110];
P dist[110][110];
set<P> edges;
long long ans;

void dijkstra(int s) {
  for (int i = 0; i < n; i++) {
    dist[s][i] = P(INF, -1);
  }
  dist[s][s] = P(0, -1);
  
  priority_queue<P, vector<P>, greater<P> > pq;
  pq.push(P(0, s));
  
  while (pq.size()) {
    P p = pq.top();
    pq.pop();
    int u = p.second;
    if (dist[s][u].first < p.first) continue;
    for (P np: edge[u]) {
      int v = np.first;
      int cost = np.second;
      if (dist[s][v].first > dist[s][u].first + cost) {
        dist[s][v] = P(dist[s][u].first + cost, u);
        pq.push(P(dist[s][v].first, v)); 
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edge[a].push_back(P(b, c));
    edge[b].push_back(P(a, c));
  }
  
  for (int i = 0; i < n; i++) {
    dijkstra(i);
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int pre = dist[i][j].second;
      if (pre == -1) continue;
      edges.insert(P(pre, j));
    }
  }
  
  ans = m - edges.size() / 2;
  cout << ans << endl;
  return 0;
}