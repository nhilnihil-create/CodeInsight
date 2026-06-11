#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Edge {
  int src, dst;
  Edge(int src, int dst) : src(src), dst(dst) {}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

bool visited[100000];
vector<int> ans1;
void sweep1(int v, const Graph &g) {
  visited[v] = true;
  for (const auto &e : g[v]) {
    if (!visited[e.dst]) {
      sweep1(e.dst, g);
      ans1.push_back(v);
      return;
    }
  }
  ans1.push_back(v);
  return;
}

vector<int> ans2;
void sweep2(int v, const Graph &g) {
  visited[v] = true;
  for (const auto &e : g[v]) {
    if (!visited[e.dst]) {
      sweep2(e.dst, g);
      ans2.push_back(v);
      return;
    }
  }
  ans2.push_back(v);
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    g[s].emplace_back(s, t);
    g[t].emplace_back(t, s);
  }
  sweep1(0, g);
  sweep2(0, g);
  ans2.pop_back();
  reverse(ans2.begin(), ans2.end());
  cout << ans1.size() + ans2.size() << endl;
  for (const auto &x : ans1) {
    cout << x + 1 << " ";
  }
  for (const auto &x : ans2) {
    cout << x + 1 << " ";
  }
}
