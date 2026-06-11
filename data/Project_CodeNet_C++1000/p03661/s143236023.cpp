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

  int n;
  cin >> n;
  vector<int64> xs(n);
  int64 sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    sum += xs[i];
  }

  int64 ans = INT64_MAX;
  int64 a = 0;
  for (int i = 0; i < n - 1; i++) {
    a += xs[i];
    int64 b = sum - a;
    UpdateMin(ans, abs(a - b));
  }
  cout << ans << endl;
}