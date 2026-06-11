
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

template <class T, class U>
inline bool chmin(T &lhs, const U &rhs) {
  if (lhs > rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T, class U>
inline bool chmax(T &lhs, const U &rhs) {
  if (lhs < rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T>
struct fix_point: private T {
  explicit constexpr fix_point(T &&func): T(std::forward<T>(func)) { }
  template <class... Args>
  constexpr decltype(auto) operator () (Args &&... args) const {
    return T::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T>
constexpr decltype(auto) make_fix_point(T &&func) {
  return fix_point<T>{std::forward<T>(func)};
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (int &x: A) {
    std::cin >> x;
  }
  std::vector<std::vector<int>> graph(N);
  for (int i = 1; i < N; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bool answer = true;
  if (N == 2) {
    std::cout << (A[0] == A[1] ? "YES" : "NO") << '\n';
    return 0;
  }
  int root = -1;
  for (int i = 0; i < N; ++i) {
    if (graph[i].size() > 1) {
      root = i;
    }
  }
  if (make_fix_point([&](auto dfs, int u, int p) -> int64_t {
    if (graph[u].size() == 1) {
      return A[u];
    }
    int64_t sum = 0, max = 0;
    for (int v: graph[u]) {
      if (v != p) {
        int64_t tmp = dfs(v, u);
        sum += tmp;
        chmax(max, tmp);
      }
    }
    int64_t pairs = sum - A[u];
    int64_t up = A[u] - pairs;
    if (pairs < 0 || std::min(sum / 2, sum - max) < pairs) {
      answer = false;
    }
    return up;
  })(root, -1) != 0) {
    answer = false;
  } 
  std::cout << (answer ? "YES" : "NO") << '\n';
  return 0;
}
