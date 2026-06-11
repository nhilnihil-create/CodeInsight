#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1, inc = 0;
  for (int i = 0; i < n - 1; i++) {
    int ninc;
    if (a[i] < a[i + 1]) {
      ninc = 1;
    } else if (a[i] > a[i + 1]) {
      ninc = -1;
    } else {
      ninc = 0;
    }
    if (inc != 0 && ninc != 0 && inc != ninc) {
      ans++;
      inc = 0;
    } else if (inc == 0) {
      inc = ninc;
    }
  }
  cout << ans << '\n';
  return 0;
}