#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> t(n), a(n);
  for (int i = 0; i < n; i++) cin >> t.at(i);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  ll ans = 1;
  vector<int> x(n, -1), y(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) x.at(i) = t.at(i);
    else if (t.at(i - 1) < t.at(i)) x.at(i) = t.at(i);
    y.at(i) = t.at(i);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      if (x.at(i) == -1) {
        if (y.at(i) < a.at(i)) ans = 0;
        x.at(i) = a.at(i);
      }
      else {
        if (x.at(i) != a.at(i)) ans = 0;
      }
    }
    else if (a.at(i) > a.at(i + 1)) {
      if (x.at(i) == -1) {
        if (y.at(i) < a.at(i)) ans = 0;
        x.at(i) = a.at(i);
      }
      else {
        if (x.at(i) != a.at(i)) ans = 0;
      }
    }
    y.at(i) = min(y.at(i), a.at(i));
  }
  
  for (int i = 0; i < n; i++) {
    if (x.at(i) == -1) {
      ans *= y.at(i);
      ans %= MOD;
    }
  }
  
  cout << ans << '\n';
}