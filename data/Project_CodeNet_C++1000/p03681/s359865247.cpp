#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  ll a, b;
  cin >> a >> b;
  if (abs(a-b) != 1 && a != b) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  if (a == b) {
    for (ll i = 1; i <= a; i++) {
      ans = (ans * i) % mod;
    }
    ans = (ans * ans) % mod;
    ans = (ans * 2) % mod;
  } else {
    if (a > b) swap(a, b);
    for (ll i = 1; i <= a; i++) {
      ans = (ans * i) % mod;
    }
    ans = (ans * ans) % mod;
    ans = (ans * b) % mod;
  }
  cout << ans << endl;
  return 0;
}
