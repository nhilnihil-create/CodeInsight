#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  ll mod = 1'000'000'007;
  ll N, M;
  cin >> N >> M;

  if (1 < abs(N-M)) {
    cout << 0 << endl;
    return 0;
  }

  ll m = max(N, M);
  vector<ll> dp(m+1); dp[0] = 1;
  for (ll i = 1; i <= m; ++i) {
    dp[i] = (dp[i-1] * i) % mod;
  }

  ll ans = (dp[N] * dp[M]);
  if (N == M) ans *= 2;
  cout << ans % mod << endl;
  return 0;
}
