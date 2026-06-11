#include <bits/stdc++.h>
using namespace std;
long long dp[2002][2002];
long long a[2002];
const long long inf = 1e18;

int main() {
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) dp[0][i] = a[i];
  for(int i = 1; i < n; i++) {
  	for(int j = 0; j < n; j++) {
      dp[i][j] = min(dp[i - 1][(j + n - 1) % n], a[j]);
    }
  }
  long long ans = inf;
  for(int i = 0; i < n; i++) {
  	long long res = 1LL * x * i;
    for(int j = 0; j < n; j++) {
      res += dp[i][j];
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
  return 0;
}