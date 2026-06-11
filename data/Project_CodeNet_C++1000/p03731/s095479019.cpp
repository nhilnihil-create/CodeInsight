#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;

int main() {
  int n, t;
  cin >> n >> t;
  vector<ll> a(n + 1);
  for (ll &i : a) {
    cin >> i;
  }
  ll ans = 0;
  a[n] = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    ans += min(a[i] + t, a[i+1]) - a[i];
  }
  cout << ans << endl;
  return 0;
}
