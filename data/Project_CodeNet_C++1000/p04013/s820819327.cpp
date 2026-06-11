#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, A, B, answer = 0;
  cin >> N >> A;
  int x[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= N; i++) {
    B = i*A;
    long long dp[i+1][N+1][B+1];
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= N; k++) {
        for (int l = 0; l <= B; l++) {
          dp[j][k][l] = 0;
        }
      }
    }
    for (int j = 0; j <= N; j++) {
      dp[0][j][0] = 1;
    }
    for (int j = 1; j <= i; j++) {
      for (int k = j; k <= N; k++) {
        for (int l = 1; l <= B; l++) {
          dp[j][k][l] = dp[j][k-1][l];
          if (l >= x[k-1]) {
            dp[j][k][l] += dp[j-1][k-1][l-x[k-1]];
          }
        }
      }
    }
    answer += dp[i][N][B];
  }
  cout << answer;
}