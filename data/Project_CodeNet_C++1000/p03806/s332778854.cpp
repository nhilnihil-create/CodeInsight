#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, Ma, Mb, A = 0, B = 0, answer = INT_MAX;
  cin >> N >> Ma >> Mb;
  int a[N], b[N], c[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i] >> c[i];
    A += a[i];
    B += b[i];
  }
  for (int m = 1; m*Ma <= A && m*Mb <= B; m++) {
    vector<vector<vector<long long>>> dp(N+1,vector<vector<long long>>(m*Ma+1,vector<long long>(m*Mb+1,INT_MAX)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j <= m*Ma; j++) {
        for (int k = 0; k <= m*Mb; k++) {
          dp[i][j][k] = dp[i-1][j][k];
          if (j-a[i-1] >= 0 && k-b[i-1] >= 0) {
            dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-a[i-1]][k-b[i-1]]+c[i-1]);
          }
        }
      }
    }
    answer = min(answer,dp[N][m*Ma][m*Mb]);
  }
  if (answer == INT_MAX) {
    cout << -1;
  }  else {
    cout << answer;
  }
}