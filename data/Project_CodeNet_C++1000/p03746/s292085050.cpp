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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  auto graph = ReadUndirectedGraph(n, m, true);

  int r1 = 0;
  int r2 = graph[r1][0].to;
  vector<int> visited(n);
  visited[r1] = 1;
  visited[r2] = 1;

  auto find_path = [&](int r) -> vector<int> {
    vector<int> path({r});
    int v = r;
    while (true) {
      bool is_end = true;
      for (const auto& e : graph[v]) {
        if (visited[e.to]) continue;
        is_end = false;
        path.push_back(e.to);
        visited[e.to] = 1;
        v = e.to;
        break;
      }
      if (is_end) break;
    }
    return path;
  };
  auto p1 = find_path(r1);
  auto p2 = find_path(r2);
  reverse(p1.begin(), p1.end());

  cout << p1.size() + p2.size() << endl;
  for (int v : p1) {
    cout << v + 1 << " ";
  }
  for (int v : p2) {
    cout << v + 1 << " ";
  }
  cout << endl;
}