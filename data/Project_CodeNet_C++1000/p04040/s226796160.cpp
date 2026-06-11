#include<bits/stdc++.h>
using namespace std;
struct _IO{_IO(){ios::sync_with_stdio(0);cin.tie(0);}}_io;
typedef long long ll; typedef long double db;
const int N = 5e5 + 5, M = 1e9 + 7;

ll qpow(ll x, ll n) {
  ll res = 1;
  for (; n; n >>= 1, x = x * x % M) if (n & 1) res = res * x % M;
  return res;
}

ll fac[N];
ll comb(ll n, ll m) {
  if (n < m) return 0;
  return fac[n] * qpow(fac[m] * fac[n - m] % M, M - 2) % M;
}

int main() {
  ll h, w, a, b;
  cin >> h >> w >> a >> b;
  fac[0] = 1;
  for (int i = 1; i <= 2 * max(h, w); i++) {
    fac[i] = fac[i-1] * i % M;
  }
  ll ans = 0;
  for (int i = b; i < w; i++) {
    ans = (ans + comb(h - a - 1 + i, i) * comb(a + w - i - 2, a - 1) % M) % M;
  }
  cout << ans;
}
