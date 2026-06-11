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

int dfs(int v, const vector<vector<int>>& g) {
  vector<int> depths;
  for (auto u : g[v]) {
    depths.push_back(dfs(u, g));
  }
  sort(depths.begin(), depths.end());
  int mx = 0;
  for (int i = (int)depths.size() - 1; i >= 0; i--) {
    mx = max(mx, depths[i] + (int)depths.size() - i);
  }
  return mx;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    --a[i];
    g[a[i]].push_back(i);
  }
  cout << dfs(0, g) << "\n";
}

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
    solve();
  }
  return 0;
}