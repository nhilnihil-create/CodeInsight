#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  UnionFind () {}
  UnionFind (int n) { init(n); }

  vector<int> parent, rank;

  void init(int n) {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i; rank[i] = 1;
    }
  }

  int root(int v) {
    return parent[v] = (parent[v] == v ? v : root(parent[v]));
  }

  bool same(int u, int v) {
    return root(u) == root(v);
  }

  bool is_root(int v) {
    return root(v) == v;
  }

  void unite(int u, int v) {
    if (same(u, v)) return;
    u = root(u); v = root(v);

    if (rank[u] > rank[v]) swap(u, v);
    rank[u] += rank[v];
    parent[v] = u;
  }

  int element_count(int v) {
    return rank[root(v)];
  }
};

int main() {
  int n, k, l;
  cin >> n >> k >> l;

  UnionFind a(n), b(n);

  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    a.unite(u, v);
  }

  for (int i = 0; i < l; ++i) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    b.unite(u, v);
  }

  map<pair<int, int>, int> m;
  for (int i = 0; i < n; ++i) {
    m[make_pair(a.root(i), b.root(i))]++;
  }

  for (int i = 0; i < n; ++i) {
    cout << m[make_pair(a.root(i), b.root(i))] << (i + 1 == n ? "\n" : " ");
  }
}
