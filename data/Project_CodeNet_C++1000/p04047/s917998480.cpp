#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector <int> v(n + n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n + n; i += 2) {
    ans += v[i];
  }
  cout << ans << endl;
  return 0;
}

