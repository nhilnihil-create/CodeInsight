#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

class UnionFind {
  std::vector<intmax_t> tree;

public:
  UnionFind(size_t n): tree(n, -1) {}

  size_t find(size_t v) {
    if (tree[v] < 0)
      return v;

    return (tree[v] = find(tree[v]));
  }

  bool unite(size_t u, size_t v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;

    if (-tree[u] >= -tree[v])
      std::swap(u, v);

    tree[v] += tree[u];
    tree[u] = v;
    return true;
  }

  bool connected(size_t u, size_t v) {
    return (find(u) == find(v));
  }

  size_t size(size_t v) {
    return -tree[find(v)];
  }
};

int main() {
  size_t W, H;
  scanf("%zu %zu", &W, &H);

  std::vector<std::pair<intmax_t, size_t>> es;
  for (size_t j=0; j<W; ++j) {
    intmax_t p;
    scanf("%jd", &p);
    es.emplace_back(p, j);
  }

  for (size_t i=0; i<H; ++i) {
    intmax_t q;
    scanf("%jd", &q);
    es.emplace_back(q, W+i);
  }

  std::sort(es.begin(), es.end());
  size_t a=W+1, b=H+1;
  intmax_t res=0;
  UnionFind uf(a+b);
  for (const auto &e: es) {
    if (uf.connected(e.second, e.second+1))
      continue;

    uf.unite(e.second, e.second+1);
    if (e.second < W) {
      res += e.first*b;
      --a;
    } else {
      res += e.first*a;
      --b;
    }
  }

  printf("%jd\n", res);
}
