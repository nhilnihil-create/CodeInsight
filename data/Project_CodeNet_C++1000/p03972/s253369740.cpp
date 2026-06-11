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

template <class RandomIt>
auto rsort(RandomIt first, RandomIt last)
  -> typename std::enable_if<std::is_integral<
    typename RandomIt::value_type::first_type>::value>::type
{
  using PairType = typename RandomIt::value_type;
  using KeyType = typename PairType::first_type;

  intmax_t cur_shift=0, max_exp=sizeof(KeyType);
  std::vector<PairType> work(last-first);
  for (int i=0; i<max_exp; ++i) {
    size_t num[256]={};

    for (RandomIt it=first; it<last; ++it)
      ++num[((it->first)>>cur_shift)&255];

    {
      size_t tmp=0;
      for (int j=0; j<256; ++j)
        std::swap(tmp, num[j]+=tmp);
    }

    for (RandomIt it=first; it<last; ++it)
      work[num[((it->first)>>cur_shift)&255]++] = *it;

    {
      size_t j=0;
      for (RandomIt it=first; it<last; ++it)
        *it = work[j++];
    }

    cur_shift += 8;
  }

  if (!std::is_signed<KeyType>::value) return;

  RandomIt mid=last;
  for (RandomIt it=last; --it>=first;)
    if ((it->first) >= 0) {
      mid = ++it;
      break;
    }

  if (mid == last)
    return;

  std::copy(first, mid, work.begin()+(last-mid));
  std::copy(mid, last, work.begin());
  std::copy(work.begin(), work.end(), first);
}

int main() {
  size_t W, H;
  scanf("%zu %zu", &W, &H);

  std::vector<std::pair<unsigned, size_t>> es;
  for (size_t j=0; j<W; ++j) {
    unsigned p;
    scanf("%u", &p);
    es.emplace_back(p, j);
  }

  for (size_t i=0; i<H; ++i) {
    unsigned q;
    scanf("%u", &q);
    es.emplace_back(q, W+i);
  }

  rsort(es.begin(), es.end());
  size_t a=W+1, b=H+1;
  uintmax_t res=0;
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

  printf("%ju\n", res);
}
