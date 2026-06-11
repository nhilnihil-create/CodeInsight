#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, A;
  cin >> N >> A;
  vector<long long> x(N);
  for (auto &xx : x) cin >> xx;

  int R = N*50;
  vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(N, vector<long long>(R+1, 0)));
  for (int i = 0; i < N; ++i) {
    dp[1][i][x[i]] = 1;
    for (int a = 0; a <= R; ++a) {
      dp[0][i][a] = 0;
    }
  }

  for (int k = 2; k <= N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int a = 0; a <= R; ++a) {
        long long sum = 0;
        for (int j = k-2; j < i; ++j) {
          if (a-x[i] >= 0) sum += dp[k-1][j][a-x[i]];
        }
        dp[k][i][a] = sum;
      }
    }
  }
  long long res = 0;
  for (int k = 1; k <= N; ++k) {
    for (int i = 0; i < N; ++i) {
      if (k*A >= x[i]) res += dp[k][i][k*A];
    }
  }
  cout << res << endl;

  return 0;
}

