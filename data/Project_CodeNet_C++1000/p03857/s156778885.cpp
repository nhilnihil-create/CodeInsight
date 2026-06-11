#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct UnionFind {
  std::vector<int> parent;
  int __size;
  UnionFind(int size_) : parent(size_, -1), __size(size_) {}
  void unite(int x, int y) {
    if ((x = root(x)) != (y = root(y))) {
      if (parent[y] < parent[x]) std::swap(x, y);
      parent[x] += parent[y];
      parent[y] = x;
      __size--;
    }
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  int size(int x) { return -parent[root(x)]; }
  int size() { return __size; }
};

int main() {
  int n, k, l;
  cin >> n >> k >> l;

  UnionFind uf1(n);
  for (int i = 0; i < k; i++) {
    int a, b; cin >> a >> b;
    uf1.unite(a-1, b-1);
  }

  UnionFind uf2(n);
  for (int i = 0; i < l; i++) {
    int a, b; cin >> a >> b;
    uf2.unite(a-1, b-1);
  }

  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    mp[make_pair(uf1.root(i), uf2.root(i))]++;
  }

  for (int i = 0; i < n; i++) {
    cout << mp[make_pair(uf1.root(i), uf2.root(i))];
    cout << (i == n-1 ? "\n" : " ");
  }

  return 0;
}