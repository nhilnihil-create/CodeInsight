#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
  x = 0; char c = getchar(); int f = 0;
  for(; c < '0' || c > '9'; f |= c == '-', c = getchar());
  for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if(f) x = -x;
}
const int N = 4e6 + 233;
namespace {
  const int mo = 1e9 + 7;
  inline int add(int x, int y) {
    if((x += y) >= mo) x -= mo;
    return x;
  }
  inline int sub(int x, int y) {
    if((x -= y) < 0) x += mo;
    return x;
  }
  inline int mul(int x, int y) {
    return x * y % mo;
  }
  inline int pw(int a, int k, int mo) {
    int ans = 1;
    for(; k; k >>= 1, a = mul(a, a))
      if(k & 1) ans = mul(ans, a);
    return ans;
  }
  inline void U(int &x, int y) {
    x = add(x, y);
  }
}
int fac[N], fac_inv[N], dp[2333][2333];
int n, k;
inline void init(void) {
  fac[0] = 1;
  for(int i = 1; i < N; i ++)
    fac[i] = mul(fac[i - 1], i);
  fac_inv[N - 1] = pw(fac[N - 1], mo - 2, mo);
  for(int i = N - 2; i >= 0; i --)
    fac_inv[i] = mul(fac_inv[i + 1], i + 1);
}

inline int C(int n, int m) {
  if(n < m) return 0;
  else if(n == m || m == 0) return 1;
  else return mul(fac[n], mul(fac_inv[m], fac_inv[n - m]));
}

main(void) {
  init();
  read(n); read(k);
  if(k == 1) return cout << 1 << "\n", 0;
  dp[0][0] = 1;
  for(int i = 1; i <= n; i ++) {
    for(int j = 0; j <= i; j ++) {
      if(j) U(dp[i][j], mul(dp[i][j - 1], C(n * k - i - (j - 1) * (k - 1) - 1, k - 2)));
      U(dp[i][j], dp[i - 1][j]);
    }
  }
  int ans = mul(dp[n][n], fac[n]);
  cout << ans << "\n";
}
