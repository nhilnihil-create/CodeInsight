#include <bits/stdc++.h>
int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  auto make_left = [&] (const auto& a) {
    std::vector<std::vector<int>> left(n + 1, std::vector<int>(k + 1, false));
    left.at(0).at(0) = true;
    for (int i = 0; i < n; i++) {
      auto& crr = left.at(i);
      auto& nxt = left.at(i + 1);
      nxt = crr;
      for (int x = 0; x + a.at(i) <= k; x++) {
        nxt.at(x + a.at(i)) |= crr.at(x);
      }
    }
    return left;
  };
  auto left  = make_left(a);
  auto right = [&]{
    auto b = a;
    std::reverse(b.begin(), b.end());
    auto ret = make_left(b);
    std::reverse(ret.begin(), ret.end());
    return ret;
  }();
  auto search = [&] (int x, const auto& l, const auto& r) {
    for (int i = k - 1; i >= 0;) {
      if (l.at(i)) {
        for (int j = std::max(0, k - x - i); j < k - i; j++) {
          if (r.at(j)) return true;
        }
        i -= x;
      } else {
        i--;
      }
    }
    return false;
  };
  int ret = 0;
  for (int i = 0; i < n; i++) {
    ret += !search(a.at(i), left.at(i), right.at(i + 1));
  }
  std::cout << ret << std::endl;
  return 0;
}