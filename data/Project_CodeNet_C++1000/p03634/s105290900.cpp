#include<iostream>
#include<list>
using namespace std;

int N; list<pair<int, long>> E[100005];
long dist[100005];
bool visited[100005];

void dfs(int u, long d) {
  dist[u] = d;
  for (auto it = E[u].begin(); it != E[u].end(); it++) {
    if (!visited[it->first]) {
      visited[it->first] = true;
      dfs(it->first, d + it->second);
    }
  }
}

int main() {
  cin >> N;
  int a, b; long c;
  for (int i = 0; i < N-1; i++) {
    cin >> a >> b >> c; a--; b--;
    E[a].push_back(make_pair(b, c)); E[b].push_back(make_pair(a, c));
  }
  int Q, K; cin >> Q >> K; K--;
  for (int i = 0; i < N; i++) visited[i] = false;
  visited[K] = true;
  dfs(K, 0);
  int x, y;
  for (int i = 0; i < Q; i++) {
    cin >> x >> y; x--; y--;
    cout << dist[x] + dist[y] << endl;
  }
}