#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    xs[i]--;
  }

  auto distance_fn = [&](int a, int b) -> int {
    if (b > a) return b - a;
    else return b + m - a;
  };

  // Returns tue if x in [l, r).
  auto in_range_fn = [&](int l, int r, int x) -> int {
    if (l <= r) {
      return l <= x && x < r;
    } else {
      return l <= x || x < r; 
    }
  };

  int delta = 0;
  vector<vector<int>> i_to_es(m);
  for (int i = 0; i + 1 < n; i++) {
    int x1 = xs[i];
    int x2 = xs[i + 1];
    int d = distance_fn(x1, x2);
    if (d >= 2) {
      i_to_es[(x1 + 2) % m].push_back(-1);
      i_to_es[(x2 + 1) % m].push_back(d - 1);
      if (in_range_fn((x1 + 2) % m, (x2 + 1) % m, 0)) {
        delta--;
      }
    }
  }

  int64 sum = 0;
  for (int i = 0; i + 1 < n; i++) {
    int x1 = xs[i];
    int x2 = xs[i + 1];
    if (x1 < x2) {
      sum += x2 - x1;
    } else {
      sum += 1 + x2;
    }
  }

  if (DEBUG) {
    cout << "i: " << 0 << " sum: " << sum << " delta: " << delta << endl;
  }

  int64 ans = sum;

  for (int i = 1; i < m; i++) {
    for (int e : i_to_es[i]) {
      if (e > 0) {
        sum += e;
        delta++;
      } else {
        delta--;
      }
    }
    sum += delta;

    if (DEBUG) {
      cout << "i: " << i << " sum: " << sum << " delta: " << delta << endl;
    }

    UpdateMin(ans, sum);
  }
  cout << ans << endl;
}