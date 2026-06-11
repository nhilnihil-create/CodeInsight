#include <bits/stdc++.h>

using namespace std;


int main() {
  int k, t;
  cin >> k >> t;
  int ma = 0;
  for (int i = 0; i < t; ++i) {
    int a;
    cin >> a;
    ma = max(a, ma);
  }
  if (t == 1) {
    cout << ma - 1 << '\n';
  } else {
    int ans = max(0, ma - 1 - (k - ma));
    cout << ans << '\n';
  }
  return 0;
}

