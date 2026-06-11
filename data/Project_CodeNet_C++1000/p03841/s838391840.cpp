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
#define DEBUG(message) std::cerr << message << std::endl;
#else
#define DEBUG(message)
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> a(n * n, -1);
  set<int> free_places;
  for (int i = 0; i < n * n; i++) {
    free_places.insert(i);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    --x[i];
    a[x[i]] = i;
    free_places.erase(x[i]);
    res += i;
  }
  auto no = []() {
    cout << "No" << endl;
    exit(0);
  };
  while (free_places.size() > res) {
    auto it = free_places.end();
    --it;
    free_places.erase(it);
  }
  for (int i = 0; i < n; i++) {
    int on_left = i;
    while (on_left--) {
      auto it = free_places.lower_bound(x[i]);
      if (it == free_places.begin()) {
        no();
      }
      --it;
      a[*it] = i;
      free_places.erase(it);
    }
  }
  free_places.clear();
  for (int i = 0; i < n * n; i++) {
    free_places.insert(i);
  }
  for (int i = 0; i < n * n; i++) {
    if (a[i] == -1) {
      continue;
    }
    free_places.erase(i);
  }
  for (int i = 0; i < n; i++) {
    int on_right = n - i - 1;
    while (on_right--) {
      auto it = free_places.lower_bound(x[i]);
      if (it == free_places.end()) {
        no();
      }
      a[*it] = i;
      free_places.erase(it);
    }
  }
  cout << "Yes\n";
  for (auto x : a) {
    cout << x + 1 << " ";
  }
  cout << "\n";
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