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
    string s;
    cin >> s;

    string t;
    cin >> t;

    int n = (int)s.size();
    int m = (int)t.size();

    vector<int> a(n + 1, 0);
    vector<int> b(m + 1, 0);

    for (int i = 1; i <= n; i++) {
      a[i] += a[i - 1];
      if (s[i - 1] == 'A') {
        ++a[i];
      }
    }

    for (int j = 1; j <= m; j++) {
      b[j] += b[j - 1];
      if (t[j - 1] == 'A') {
        ++b[j];
      }
    }

    auto calc_a = [](const auto& array, int l, int r) {
      return array[r] - array[l - 1];
    };
    auto calc_b = [&](const auto& array, int l, int r)  {
      return r - l + 1 - calc_a(array, l, r);
    };
    auto repeat = [](char ch, int x) {
      string s;
      while (x--) {
        s += ch;
      }
      return s;
    };
    auto compress = [&](int sa, int sb) {
      if (sa > sb) {
        return repeat('A', (sa - sb) % 3);
      } else {
        return repeat('B', (sb - sa) % 3);
      }
    };
    auto convert_to_a = [](const string& s) -> string {
      if (s == "B") {
        return "AA";
      } else if (s == "BB") {
        return "A";
      } else {
        return s;
      }
    };

    int q;
    cin >> q;
    while (q--) {
      int l, r, x, y;
      cin >> l >> r >> x >> y;

      int sa = calc_a(a, l, r);
      int sb = calc_b(a, l, r);

      int ta = calc_a(b, x, y);
      int tb = calc_b(b, x, y);

      DEBUG("" << sa << " " << sb << " " << ta << " " << tb);

      string ss = compress(sa, sb);
      string tt = compress(ta, tb);

      DEBUG("" << ss << " " << tt);

      string css = convert_to_a(ss);
      string ctt = convert_to_a(tt);

      DEBUG("" << css << " " << ctt);

      if (css == ctt) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
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