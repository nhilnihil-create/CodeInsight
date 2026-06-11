#include <bits/stdc++.h>
using namespace std;

// Union-Find木
struct UnionFind {
  vector<int> par;
  
  // Constructor
  UnionFind(int n): par(n) {
    for (int i = 0; i < n; i++) par[i] = i;
  }
  
  // n要素で初期化
  void init(int n) {
    par.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;
  }
  
  // 根の検索
  int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  }
  
  // xとyの属する集合を併合
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    par[x] = y;
    return true;
  }
  
  // xとyが同じ集合に属するか
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 無向(有向)グラフの隣接リスト
  int n, m; // n:頂点数 m:辺数
  cin >> n >> m;
  
  vector<int> G[n]; // G:頂点数がnのグラフを表す隣接リスト
  
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u); // 有向グラフではこの行をコメントアウト
  }
  
  UnionFind uf(n);
  deque<int> dq;
  dq.emplace_front(0);
  
  while (true) {
    bool next = false;
    for(int i = 0; i < G[dq.back()].size(); i++) {
      if (!uf.same(dq.back(), G[dq.back()][i])) {
        uf.unite(dq.back(), G[dq.back()][i]);
        dq.emplace_back(G[dq.back()][i]);
        next = true;
        break;
      }
    }
    if (!next) break;
  }
  while (true) {
    bool next = false;
    for(int i = 0; i < G[dq.front()].size(); i++) {
      if (!uf.same(dq.front(), G[dq.front()][i])) {
        uf.unite(dq.front(), G[dq.front()][i]);
        dq.emplace_front(G[dq.front()][i]);
        next = true;
        break;
      }
    }
    if (!next) break;
  }
  
  cout << dq.size() << '\n';
  while (!dq.empty()) {
    cout << dq.front() + 1;
    dq.pop_front();
    if (!dq.empty()) cout << " ";
  }
}