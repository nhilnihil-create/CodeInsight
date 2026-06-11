#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    return a - mod;
  }
  if (a < 0) {
    return a + mod;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, mod - 2));
}

const int N = 2000 * 2000 + 7;
const int L = 2000 + 7;
int fact[N], inv[N];
int n, k, dp[L][L];

int comb(int n, int k) {
  int x = fact[n];
  int y = mul(inv[k], inv[n - k]);
  return mul(x, y);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  inv[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    inv[i] = mul(i + 1, inv[i + 1]);
  }
  cin >> n >> k;
  if (k == 1) {
    cout << "1\n";
    return 0;
  }
  dp[0][0]=1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j) {
        dp[i][j] = add(dp[i][j], mul(dp[i][j - 1], comb(n - i + (n - j + 1) * (k - 1) - 1, k - 2)));
      }
    }
  }
  int ans = dp[n][n];
  ans = mul(ans, fact[n]);
  cout << ans << "\n";
}
