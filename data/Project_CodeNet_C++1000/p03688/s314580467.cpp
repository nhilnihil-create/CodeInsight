#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto is_valid = [&] (int x) {
    for (int i = 0; i < n; i++) if (a[i] != x && a[i] + 1 != x) return false;
    int alone = 0;
    for (int i = 0; i < n; i++) if (a[i] + 1 == x) alone++;
    int paired = n - alone;
    if (paired == 1) return false;
    return (alone + (paired > 0)) <= x && x <= (alone + paired / 2);
  };
  for (int x : {a[0], a[0] + 1}) if (is_valid(x)) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}