# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ui32 = unsigned int;
constexpr ll INFLL = 1e18;

#define CHECK_IMPL1(cond)              \
if (!(cond)) {                         \
    DEBUG("expected cond: " << #cond); \
    assert(cond);                      \
}

#define CHECK_IMPL2(cond, message)                                            \
if (!(cond)) {                                                                \
    DEBUG("expected cond: " << #cond << " failed with message: " << message); \
    assert(cond);                                                             \
}
#define CHECK_IMPL(_1, _2, NAME, ...) NAME
#define CHECK(...) CHECK_IMPL(__VA_ARGS__, CHECK_IMPL2, CHECK_IMPL1, CHECK_IMPL0)(__VA_ARGS__)

#ifdef __APPLE__
#define DEBUG(message) std::cerr << message << "\n";
#else
#define DEBUG(message)
#endif

struct Solver {
  void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    used.resize(n, false);
    for (int i = 0; i < n; i++) {
      if (g[i].size() > 1) {
        auto value = dfs(i);
        if (value == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
        return;
      }
    }
    if (n == 2 && a[0] == a[1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  ll dfs(int v) {
    used[v] = true;

    vector<ll> vv;
    ll total = 0;
    int child_count = 0;
    for (auto u : g[v]) {
      if (used[u]) {
        continue;
      }

      ++child_count;
      auto value = dfs(u);
      vv.push_back(value);
      total += value;
    }

    if (!child_count) {
      return a[v];
    }

    sort(vv.begin(), vv.end());

    auto calc_value = [](const auto& values) {
      ll res = 0;
      ll sum = 0;
      for (auto value : values) {
        sum += value;
      }
      if (sum - values.back() < values.back()) {
        return sum - values.back();
      }
      return sum / 2;
    };

    auto matches = calc_value(vv);

    if (a[v] > total || a[v] < total - matches) {
      DEBUG("v: " << v << " a[v]: " << a[v] << " total: " << total << " matches: " << matches);
      cout << "NO\n";
      exit(0);
    }

    DEBUG("v: " << v << " res: " << total - 2ll * a[v]);
    return 2 * a[v] - total;
  }

  int n;
  vector<int> a;
  vector<vector<int>> g;
  vector<bool> used;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  int t = 1;
//  cin >> t;
  for (int i = 1; i <= t; i++) {
    Solver().solve();
  }
  return 0;
}