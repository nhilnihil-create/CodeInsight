#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  const ll md = 1000000007;
  ll n, m;
  cin >> n >> m;

  ll ans;
  if (abs(n - m) >= 2) {
    ans = 0;
  } else {
    ll mx = max(n, m);
    ll fact[mx + 1];
    fact[0] = 1;
    for (int i = 1; i <= mx; i++) {
      fact[i] = fact[i - 1] * i % md;
    }

    if (abs(n - m) == 1) {
      ans = fact[n] * fact[m] % md;
    } else {
      ans = fact[n] * fact[m] * 2 % md;
    }
  }

  cout << ans << endl;
  return 0;
}
