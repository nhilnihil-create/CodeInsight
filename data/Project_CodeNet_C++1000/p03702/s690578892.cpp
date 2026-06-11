#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

tuple<int64, int64> BinarySearch(const function<bool(int64)>& is_upper_fn, int64 l, int64 u) {
  while (u - l >= 2) {
    int64 m = (u + l) / 2;
    if (is_upper_fn(m)) {
      u = m;
    } else {
      l = m;
    }
  }
  return make_tuple(l, u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int64 a, b;
  cin >> n >> a >> b;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  auto fn = [&](int64 k) -> bool {
    int64 c = 0;
    for(int64 x : xs) {
      if (x > b * k) {
        c += (x - b * k + (a - b - 1)) / (a - b);
      }
    }
    return c <= k;
  };
  int64 u;
  tie(ignore, u) = BinarySearch(fn, 0, 1E9);
  cout << u << endl;
}