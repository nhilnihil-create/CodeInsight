#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> dp(n + 2, 0);
  dp[n] = n;
  if(n > 1)
  dp[n - 1] = (n * n) % MOD;
  if(n > 2)
  dp[n - 2] = ((2 * n - 1) * n) % MOD;
  for(long long i = n - 3, cur = n - 1; i >= 1; i--)
  {
    (cur += dp[i + 3] + MOD - 1) %= MOD;
    (dp[i] += (n - 1) * (n - 1)) %= MOD;
    (dp[i] += dp[i + 1]) %= MOD;
    (dp[i] += cur) %= MOD;
  }
  cout << dp[1] << endl;
  return 0;
}
