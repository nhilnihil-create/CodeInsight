#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  int ans = 1;
  for (int i = 1, beg = t[0], num = 1; i < n; i++) {
    if (t[i] - beg <= k && num < c) {
      num++;
    } else {
      ans++;
      beg = t[i];
      num = 1;
    }
  }
  cout << ans << '\n';
  return 0;
}