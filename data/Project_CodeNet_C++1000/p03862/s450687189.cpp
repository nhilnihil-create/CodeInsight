#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main() {
  int n;
  i64 x;
  cin >> n >> x;
  vector<i64> a(n);
  for (i64& x : a) cin >> x;
  vector<i64> b(a);
  b[0] = min(b[0], x);
  for (int i = 1; i < n; i++) {
    b[i] = min(x - b[i - 1], b[i]);
  }
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] - b[i];
  }
  cout << ans << '\n';
}