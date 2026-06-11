#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ll n, a, x[50], dp[51][51][2501] = {};
  scanf("%lld %lld", &n, &a);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &x[i]);
    dp[i + 1][1][x[i]] = 1;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < 2501 - x[i]; k++) {
        dp[i + 1][j][k] += dp[i][j][k];
        dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
      }
    }
  }
  ll o = 0;
  for(int i = 0; i <= n; i++) o += dp[n][i][a * i];
  printf("%lld\n", o);
}