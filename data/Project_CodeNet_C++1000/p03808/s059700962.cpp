#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}
template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

constexpr int DEBUG = 1;

bool Solve() {
  int n;
  cin >> n;
  
  vector<int64> xs(n);
  int64 x_sum = 0;
  int64 u = 0;
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    x_sum += xs[i];
    u += i + 1;
  }

  if (x_sum % u != 0) {
    return false;
  }
  
  int64 m = x_sum / u;

  vector<int64> counts(n);
  for (int i = 0; i < n; i++) {
    int64 d = m + xs[(i + n - 1) % n] - xs[i];
    // cout << "i: " << i << " d: " << d << endl;
    if (d < 0 || d % n != 0) return false;
    counts[i] = d / n;
  }

  int64 count_sum = 0;
  for (int64 count : counts) count_sum += count;

  return count_sum == m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  if (Solve()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}