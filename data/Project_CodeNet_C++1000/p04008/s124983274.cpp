#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Edge {
  const int from, to;
  Edge(int from, int to) : from(from), to(to) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int k;
  cin >> n >> k;
  vector<int> ps(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i];
    ps[i]--;
  }

  int ans = 0;
  if (ps[0] != 0) {
    ans++;
    ps[0] = 0;
  }

  vector<vector<Edge>> graph(n);
  for (int i = 1; i < n; i++) {
    graph[ps[i]].emplace_back(ps[i], i);
  }

  function<tuple<int, int>(int)> dfs = [&](int v) -> tuple<int, int> {
    if (graph[v].empty()) {
      return make_tuple(0, 0);
    }
    int cost = 0;
    int depth = 0;
    for (const auto& e : graph[v]) {
      int c_cost, c_depth;
      tie(c_cost, c_depth) = dfs(e.to);
      cost += c_cost;
      if (v != 0 && c_depth >= k - 1) {
        cost++;
      } else {
        depth = max(depth, c_depth + 1);
      }
    }
    return make_tuple(cost, depth);
  };

  int cost;
  tie(cost, ignore) = dfs(0);
  ans += cost;

  cout << ans << endl;
}