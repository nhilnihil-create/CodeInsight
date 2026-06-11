#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <utility>
const int maxn = 2005;
using ll = long long;
const ll ha = 1000000007LL;
ll pow_mod(ll a, ll b) {
  ll ans = 1, res = a;
  while(b) {
    if(1LL & b) ans = ans * res % ha;
    res = res * res % ha; b >>= 1;
  }
  return ans;
}
ll inv(ll x) {
  return pow_mod(x, ha - 2LL);
}

ll fac[maxn * maxn], ifac[maxn * maxn];
void process() {
  fac[0] = 1;
  const int n = 4000005;
  for(int i = 1; i <= n; i ++) {
    fac[i] = fac[i - 1] * (ll)i % ha;
  }
  ifac[n] = inv(fac[n]);
  for(int i = n - 1; i >= 0; i --) {
    ifac[i] = ifac[i + 1] * (ll(i + 1)) % ha;
  }
}
ll C(int n, int m) {
  if(n < m) return 0;
  ll ret = fac[n] * ifac[n - m] % ha;
  ret = ret * ifac[m] % ha;
  return ret;
}

int main() {
  process();
  int n, k; scanf("%d%d", &n, &k);
  if(k == 1) {
    puts("1"); return 0;
  }
  static ll f[maxn];
  f[0] = 1;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= i; j ++) {
      ll delta = n - j + 1;
      delta = delta * C(n * k - i - (j - 1) * (k - 1) - 1, k - 2) % ha;
      delta = delta * f[j - 1] % ha;
      f[j] += delta;
      if(f[j] >= ha) f[j] -= ha;
    }
  }
  printf("%lld\n", f[n]);
  return 0;
}