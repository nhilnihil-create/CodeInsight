#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  map<int, ll> p;
  for (int i = 2; i <= n; i++) {
    int ix = i;
    int px = 2;
    while (px*px <= ix) {
      if (ix % px == 0) {
          ll cnt = 0;
          while (ix % px == 0) ix /= px, cnt++;
          p[px] += cnt;
      }
      px++;
    }
    if (ix > 1) p[ix] += 1;
  }
  ll ans = 1;
  for (auto &i : p) {
    ans = (ans * ((i.second + 1) % mod)) % mod;
  }
  cout << ans << endl;
  return 0;
}
