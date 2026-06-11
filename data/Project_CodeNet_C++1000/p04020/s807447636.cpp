#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 1) {
      if (i + 1 < n && a[i + 1] > 0) {
        --a[i];
        --a[i + 1];
        ++res;
      }
    }
  }
  for (int i = 0; i < n; i++)
    res += a[i] / 2;
  cout << res << '\n';
  return 0;
}