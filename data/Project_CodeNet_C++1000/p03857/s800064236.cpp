#include <bits/stdc++.h>
using namespace std;


int n, k, l;
const int MAX_N = 2 * 1e5;

struct UF {
  std::vector<int> par, rank;
  UF(int n) : par(n), rank(n, 0) {
    for (size_t i = 0; i < n; ++i) par[i] = i;
  }

  int root(int x) {
    return (par[x] == x) ? x : par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    x = root(x); y = root(y);

    if (x == y) return;

    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }
};

int main() {
  cin >> n >> k >> l;
  UF u1(MAX_N), u2(MAX_N);
  for (int i = 0; i < k; ++i) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    u1.unite(p, q);
  }
  for (int i = 0; i < l; ++i) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    u2.unite(p, q);
  }
  map<pair<int, int>, int> chie;
  for (int i = 0; i < n; ++i) {
    chie[make_pair(u1.root(i), u2.root(i))]++;
  }

  for (int i = 0; i < n; ++i) {
    cout << chie[make_pair(u1.root(i), u2.root(i))] << (i == n - 1 ? '\n' : ' ');
  }
}
