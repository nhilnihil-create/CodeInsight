#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int md = 1e9 + 7;

int main(int argc, const char *argv[]) {
  ll n, m;
  cin >> n >> m;
  vector<ll> fact(n + m + 1);
  fact[1] = 1;
  for (ll i = 2; i < fact.size(); i++) {
    fact[i] = fact[i - 1] * i % md;
  }
  
  ll ans = 0, total = n + m, half = total / 2;
  if (min(n, m) != half) {
    cout << ans << '\n';
    return 0;
  }

  if (total % 2 == 1) {
    ans = fact[half] * fact[half + 1] % md;
  } else {
	ans = fact[half] * fact[half] % md;
    ans = ans * 2 % md;
  }
  
  cout << ans << '\n';
  return 0;
}