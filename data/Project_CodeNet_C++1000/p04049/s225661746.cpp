#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Edge {
  const int from, to;
  Edge(int from, int to) : from(from), to(to) {}
};

vector<vector<Edge>> ReadUndirectedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(Edge(v1, v2));
    graph[v2].push_back(Edge(v2, v1));
  }
  return graph;
}

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}
template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  auto graph = ReadUndirectedGraph(n, n - 1, true);

  vector<int> visited(n, 0);
  function<void(int, int, int)> dfs = [&](int v, int p, int d) {
    visited[v] = 1;
    if (d == 0) return;
    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      dfs(e.to, v, d - 1);
    }
  };

  int ans = n;

  if (k % 2 == 1) {
    for (int v1 = 0; v1 < n; v1++) {
      for (const Edge& e : graph[v1]) {
        int v2 = e.to;

        fill(visited.begin(), visited.end(), 0);
        dfs(v1, v2, (k - 1) / 2);
        dfs(v2, v1, (k - 1) / 2);

        int count = 0;
        for (int i = 0; i < n; i++) if (!visited[i]) count++;
        UpdateMin(ans, count);
      }
    }
  } else {
    for (int v = 0; v < n; v++) {
      fill(visited.begin(), visited.end(), 0);
      dfs(v, -1, k / 2);
      int count = 0;
      for (int i = 0; i < n; i++) if (!visited[i]) count++;
      UpdateMin(ans, count);
    }
  }
  cout << ans << endl;
}