#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
#define rem(i, m, n) for (int i = m; i > n; --i)
typedef long long ll;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll solve() {
  COMinit();
  ll H, W, A, B;
  cin >> H >> W >> A >> B;
  ll ans = 0;
  ll h = H - A;
  ll w = W - B;
  rep(i, 0, h) {
    ans = (ans + COM(i + B - 1, B - 1) * COM(H - i - 2 + w, w - 1)) % MOD;
  }
  return ans;
}

int main() {
  cout << solve() << endl;
  return 0;
}
