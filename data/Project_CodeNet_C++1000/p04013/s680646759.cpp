#include <bits/stdc++.h>
using namespace std;

int N, A;

// dp[j][k][s] ... x_1 から x_j から k 枚選んで x_i の合計を s にするような選び方の総数
// 0 ≦ j ≦ N, 0 ≦ k ≦ N, 0 ≦ s ≦ NX
long long dp[51][51][2501];

int main() {

  cin >> N >> A;

  vector<int> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }

  dp[0][0][0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= 2500; k++) {
        
        if (0 < j && (k - x[i - 1]) >= 0) {
          dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i - 1]];
        } else {
          dp[i][j][k] = dp[i - 1][j][k];
        }
      }
    }
  }

  long long sum = 0;

  for (int i = 1; i <= N; i++) {
    sum += dp[N][i][i * A];
  }
  
  cout << sum << endl;
  
  return 0;

}