#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, mod = 1e9 + 7;

int f[maxn][maxn], n, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> K;
  if( K == 1) {
    return cout << "1\n", 0;
  }
  vector<int> fac(maxn*maxn), ifac(maxn*maxn);
  for ( int i = fac[0] = 1; i < fac.size(); ++ i) {
    fac[i] = 1LL * fac[i-1] * i % mod;
  }
  function<int(int, int)> _pow = [&](int x, int n) {
    int ret = 1;
    for ( ; n; n >>= 1, x = 1LL * x * x % mod) {
      if( n & 1) {
        ret = 1LL * ret * x % mod;
      }
    }
    return ret;
  };
  ifac[fac.size()-1] = _pow(fac[fac.size()-1], mod - 2);
  for ( int i = fac.size()-1; i; -- i) {
    ifac[i-1] = 1LL * ifac[i] * i % mod;
  }
  function<int(int, int)> C = [&](int n, int m) {
    return 1LL * fac[n] * ifac[m] % mod * ifac[n-m] % mod;
  };
  f[0][0] = 1;
  for ( int i = 1; i <= n; ++ i) {
    for ( int k = 0; k <= i; ++ k) {
      f[i][k] = f[i-1][k];
      if( k) {
        f[i][k] = (f[i][k] + 1LL * f[i][k-1] * (n - k + 1) % mod * C(n-i+(K-1)*(n-k+1)-1, K-2) % mod) % mod;
      }
    }
  }
  cout << f[n][n] << "\n";
  return 0;
}