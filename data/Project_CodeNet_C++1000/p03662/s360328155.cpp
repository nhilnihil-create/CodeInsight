#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int> bfs(const vector<vector<int>> &G, int start) {
  vector<int> dist(G.size(), -1);
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u: G[v]) {
      if (dist[u] == -1) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
  return dist;
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> fdist = bfs(G, 0);
  vector<int> sdist = bfs(G, N - 1);
  int fennec = 0, snuke = 0;
  for (int v = 0; v < N; v++) {
    if (fdist[v] <= sdist[v]) {
      ++fennec;
    } else {
      ++snuke;
    }
  }
  cout << (fennec > snuke ? "Fennec" : "Snuke") << endl;
  return 0;
}
