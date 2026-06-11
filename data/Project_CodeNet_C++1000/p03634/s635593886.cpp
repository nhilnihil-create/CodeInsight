#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;

int n, q, k;
vector<P> edge[110000];
queue<int> que;
long long dist[110000];
bool done[110000];

void dfs(int u) {
  done[u] = true;
  for (P p: edge[u]) {
    int v = p.first, d = p.second;
    if (done[v]) continue;
    dist[v] = dist[u] + d;
    dfs(v);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a].push_back(P(b, c));
    edge[b].push_back(P(a, c));
  }
  cin >> q >> k;
  
  dfs(k);
  
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << dist[x] + dist[y] << endl;
  }
  
  return 0;
}