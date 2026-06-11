#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // vector<int> xs({1, 1, 1, 2, 2, 2, 3, 3, 3});
  // cout << lower_bound(xs.begin(), xs.end(), 2) - xs.begin() << endl;
  // cout << upper_bound(xs.begin(), xs.end(), 2) - xs.begin() << endl;

  int n;
  int64 len;
  int64 t;
  cin >> n >> len >> t;
  vector<int64> p_xs;
  vector<int64> n_xs;
  for (int i = 0; i < n; i++) {
    int64 x;
    int w;
    cin >> x >> w;
    if (w == 1) {
      p_xs.push_back(x);
    } else {
      n_xs.push_back(x);
    }
  }

  int64 m = 2 * ((t + len - 1) / len) + 1;

  auto count_leq_pos = [&](int64 k) -> int64 {
    int64 a = k - t;
    if (a < 0) return 0;
    return a / len * p_xs.size()
        + (upper_bound(p_xs.begin(), p_xs.end(), a % len) - p_xs.begin());
  };

  auto count_leq_neg = [&](int64 k) -> int64 {
    int64 a = k + t;
    return a / len * n_xs.size()
        + (upper_bound(n_xs.begin(), n_xs.end(), a % len) - n_xs.begin());
  };

  auto solve = [&](int i) -> int64 {
    int64 l = 0;
    int64 u = (2 * m + 1) * len;
    while (u - l >= 2) {
      int64 middle = (l + u) / 2;
      int64 count = count_leq_pos(middle) + count_leq_neg(middle);
      if (count >= m * n + i + 1) {
        u = middle;
      } else {
        l = middle;
      }
    }
    if (DEBUG) cout << "u: " << u << endl;
    return u % len;
  };
  
  for (int i = 0; i < n; i++) {
    cout << solve(i) << endl;
  }
}