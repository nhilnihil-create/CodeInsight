#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N[2];
vector<ll> X[2];
const ll MOD = 1e9 + 7;
ll Res = 1;

int main() {
  cin >> N[0] >> N[1];
  for (ll k : {0, 1}) {
    ll n = N[k];
    vector<ll> &x = X[k];
    x.resize(n);
    for (ll i = 0; i < n; ++i) cin >> x[i];
    ll res = 0;
    for (ll i = 1; i < n; ++i)
      (res += (x[i] - x[i - 1]) * i % MOD * (n - i) % MOD) %= MOD;
    (Res *= res) %= MOD;
  }
  cout << Res << endl;
  return 0;
}
