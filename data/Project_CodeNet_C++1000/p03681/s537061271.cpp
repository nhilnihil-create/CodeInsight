#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MOD = 1e9 + 7;

ll factorial_m(ll n) {
  if (n == 1) return 1;
  return n * factorial_m(n - 1) % MOD;
}

int main() {
  int n, m;
  cin >> n >> m;

  if (abs(n - m) > 1) {
    cout << 0 << endl;
    return 0;
  }

  ll dog = factorial_m(n);
  ll mon = factorial_m(m);
  ll ans = dog * mon % MOD;
  if (n == m) {
    ans = ans * 2 % MOD;
  }

  cout << ans << endl;
}
