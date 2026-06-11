#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

template <typename F>
class FixPoint : F {
public:
  explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)) {}

  template <typename... Args>
  constexpr decltype(auto)
  operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <typename F>
static inline constexpr decltype(auto) makeFixPoint(F &&f) noexcept {
  return FixPoint<F>{std::forward<F>(f)};
}

namespace null_null {

void main_() {
  size_t N;
  std::cin >> N;
  std::vector<std::vector<intmax_t>> child(N);
  for (size_t i = 0; i < N - 1; i++) {
    intmax_t a;
    std::cin >> a;
    a--;
    child[a].push_back(i + 1);
  }

  auto result = makeFixPoint([](auto dfs, auto &child, int n) -> intmax_t {
    std::vector<int> v;
    for (auto x : child[n]) {
      v.push_back(dfs(child, x));
    }
    std::sort(v.begin(), v.end(), std::greater<intmax_t>());

    int res = 0;
    for (size_t i = 0; i < v.size(); i++) {
      res = std::max(res, (int)(v[i] + i + 1));
    }

    return res;
  });

  std::cout << result(child, 0) << std::endl;
  return;
}

} // namespace null_null

int main() {
  null_null::main_();
  return 0;
}
