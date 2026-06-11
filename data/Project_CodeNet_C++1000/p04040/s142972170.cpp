#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll kai[200010];

ll mydiv(ll a, ll b) {
  if (b == 0) return 1LL;
  ll ans = mydiv(a, b / 2);
  ans *= ans;
  ans %= MOD;
  if (b&1) ans *= a;
  return ans % MOD;
}

ll pos(ll hh, ll ww) {
  hh--;
  ww--;
  ll p = kai[hh + ww];
  p *= mydiv(kai[ww], MOD - 2);
  p %= MOD;
  p *= mydiv(kai[hh], MOD - 2);
  p %= MOD;
  return p;
}

int main(){
  kai[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= MOD;
  }

  ll h, w, a, b;
  cin >> h >> w >> a >> b;
  ll ans = 0;
  for (int hh = 1; hh <= h - a; hh++) {
    ans += pos(hh, b) * pos(h - hh + 1, w - b);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
