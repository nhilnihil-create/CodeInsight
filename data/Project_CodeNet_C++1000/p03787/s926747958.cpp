#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

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

// Verified: ABC131F, ABC126E
vector<vector<int>> ConnectedComponents(const vector<vector<Edge>>& graph) {
  int n = graph.size();
  vector<vector<int>> components;
  vector<int> visited(n);

  function<void(int)> dfs = [&](int v) {
    if (visited[v]) return;
    visited[v] = true;
    components[components.size() - 1].push_back(v);
    for (auto e : graph[v]) {
      if (visited[e.to]) continue;
      dfs(e.to);
    }
  };

  for (int s = 0; s < n; s++) {
    if (visited[s]) continue;
    components.push_back(vector<int>());
    dfs(s);
  }
  return components;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  auto graph = ReadUndirectedGraph(n, m, true);
  auto components = ConnectedComponents(graph);

  int64 a = 0;
  int64 b = 0;
  int64 c = 0;
  vector<int> colors(n, -1);
  function<bool(int, int, int)> is_bipartite_fn = [&](int v, int p, int color) -> bool {
    if (colors[v] >= 0) {
      return colors[v] == color;
    }

    colors[v] = color;

    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      if (!is_bipartite_fn(e.to, v, color ^ 1)) return false;
    }
    
    return true;
  };

  for (const auto& component : components) {
    if (component.size() == 1) {
      c++;
    } else {
      if (is_bipartite_fn(component[0], -1, 0)) {
        b++;
      }else {
        a++;
      }
    }
  }

  // cout << a << " " << b << " " << c << endl;

  int64 ans = 2LL * c * n - c * c + (a + b) * (a + b) + b * b;
  cout << ans << endl;
}
