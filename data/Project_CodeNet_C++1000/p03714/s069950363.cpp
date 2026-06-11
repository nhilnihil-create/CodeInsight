#include <bits/stdc++.h>

int main() {
  int64_t n;
  std::cin >> n;

  std::vector<int64_t> a(3 * n);

  for (auto &i : a) {
    std::cin >> i;
  }

  std::multiset<int64_t> r, g;
  std::multiset<int64_t, std::greater<int64_t>> l;

  for (int64_t i = 0; i < 3 * n; i++) {
    if (i < n) {
      r.insert(a[i]);
    } else {
      l.insert(a[i]);
    }
  }

  for (int64_t i = 0; i < n; i++) {
    g.insert(*l.cbegin());
    l.erase(l.cbegin());
  }

  int64_t r_val = std::accumulate(r.cbegin(), r.cend(), 0ll),
    l_val = std::accumulate(l.cbegin(), l.cend(), 0ll),
    ans = r_val - l_val;

  for (int64_t i = 0; i < n; i++) {
    const auto v = a[i + n];

    if (*r.cbegin() < v) {
      r_val += v - *r.cbegin();
      r.erase(r.cbegin());
      r.insert(v);
    }

    auto itr = l.find(v);
    if (itr != l.cend()) {
      l_val += *g.cbegin() - v;
      l.erase(itr);
      l.insert(*g.cbegin());
      g.erase(g.cbegin());
    } else {
      auto itr = g.find(v);
      if (itr != g.cend()) {
        g.erase(itr);
      }
    }
    ans = std::max(ans, r_val - l_val);
  }

  std::cout << ans << std::endl;
  return 0;
}
