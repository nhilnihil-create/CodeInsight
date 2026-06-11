#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10, MOD = (int) 1e9+7;

void add(long long& a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

void sub(long long& a, long long b) {
  a -= b;
  if (a < 0) a += MOD;
}

long long mul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

long long fac[MAXN], inv[MAXN];

void pre() {
  fac[0] = fac[1] = 1;
  inv[0] = inv[1] = power(1, MOD - 2);
  for (int i = 2; i < MAXN; i++) {
    fac[i] = mul(i, fac[i - 1]);
    inv[i] = power(fac[i], MOD - 2);
  }
}

long long ncr(int n, int r) {
  if (r > n) return 0;
  return mul(fac[n], mul(inv[r], inv[n - r]));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pre();
  long long h, w, a, b;
  cin >> h >> w >> a >> b;
  long long ans = 0;
  for (int i = b; i < w; i++) {
    int x = h - a - 1, y = i;
    long long w1 = ncr(x + y, x);
    long long w2 = ncr(a + w - i - 2, a - 1);
    add(ans, mul(w1, w2));
  }
  cout << ans << "\n";
  return 0;
}
