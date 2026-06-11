#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

struct Edge {
  const int from, to;
  Edge(int from, int to) : from(from), to(to) {}
};

// Vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
	for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
		s << v[i];
  }
  s << "]";
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int k;
  cin >> k;
  k = min(k, n);

  vector<int> ps(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i];
    ps[i]--;
  }

  int ans = 0;
  if (ps[0] != 0) {
    ps[0] = 0;
    ans++;
  }

  vector<vector<Edge>> graph(n);
  for (int v = 1; v < n; v++) {
    int p = ps[v];
    graph[p].push_back(Edge(p, v));
  }

  vector<int> ds(n, -1);
  function<void(int, int)> dfs_1_fn = [&](int v, int p) {
    if (p == -1) ds[v] = 0;
    else ds[v] = ds[p] + 1;

    for (const auto& e : graph[v]) {
      dfs_1_fn(e.to, v);
    }
  };
  dfs_1_fn(0, -1);

  // cout << "ds: " << ds << endl;

  // (v, d)
  vector<tuple<int, int>> vds;
  for (int v = 0; v < n; v++) {
    vds.push_back({v, ds[v]});
  }
  sort(vds.begin(), vds.end(), [](const auto& vd1, const auto& vd2) {
    return get<1>(vd1) > get<1>(vd2);
  });

  vector<int> covered(n);
  // for (int v = 0; v < n; v++) {
  //   if (ds[v] <= k) {
  //     covered[v] = 1;
  //   }
  // }

  function<void(int)> dfs_2_fn = [&](int v) {
    if (covered[v]) return;
    covered[v] = true;
    for (const auto& e : graph[v]) {
      dfs_2_fn(e.to);
    }
  };

  for (const auto& vd : vds) {
    int v = get<0>(vd);
    if (ds[v] <= k) continue;
    if (covered[v]) continue;
    for (int i = 0; i < k - 1; i++) {
      if (ps[v] != -1) v = ps[v];
    }
    dfs_2_fn(v);
    ans++;
  }

  cout << ans << endl;
}