#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
int main() {
  int n, A;
  cin >> n >> A;
  int x[n];
  long long ans = 0;
  for(int i=0;i<n;i++) {
    cin >> x[i];
  }
  vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(n+1, vector<long long>(n*A+1)));
  for(int i=0;i<n+1;i++) {
    for(int j=0;j<n+1;j++) {
      if(j > i) break;
      for(int k=0;k<n*A+1;k++) {
        if(i == 0) {
          if(k == 0) dp[i][j][k] = 1;
          else dp[i][j][k] = 0;
        }
        else if(j == 0) {
          if(k == 0) dp[i][j][k] = 1;
          else dp[i][j][k] = 0;
        }
        else if(x[i-1] > k) dp[i][j][k] = dp[i-1][j][k];
        else dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i-1]];
      }
    }
  }
  for(int i=1;i<n+1;i++) {
    ans += dp[n][i][i*A];
  }
  cout << ans << endl;
}

