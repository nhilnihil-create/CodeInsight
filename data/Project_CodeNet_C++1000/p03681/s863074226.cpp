#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  const ll m = 1e9 + 7;
  ll a, b;
  cin >> a >> b;
  if (abs(a - b) == 1 || a - b == 0) {
    ll k = max(a, b);
    ll fact[k + 1];
    fact[0] = 1;
    for (ll i = 1; i <= k; i++) {
      fact[i] = fact[i - 1] * i % m;
    }
    if (abs(a - b) == 1)
      cout << fact[a] * fact[b] % m << endl;
    else
      cout << fact[a] * fact[b] * 2ll % m << endl;
  } else
    cout << "0" << endl;
}