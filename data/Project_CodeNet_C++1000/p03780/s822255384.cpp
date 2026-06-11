#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
    a[i] = min(a[i], K);
  }
  vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++){
    for (int j = 0; j <= K; j++){
      int next = min(j + a[i], K);
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
      dp[i + 1][next] += dp[i][j];
      dp[i + 1][next] %= MOD;
    }
  }
  vector<vector<int>> dp2(N + 1, vector<int>(K + 1, 0));
  dp2[N][0] = 1;
  for (int i = N - 1; i >= 0; i--){
    for (int j = 0; j <= K; j++){
      int next = min(j + a[i], K);
      dp2[i][j] += dp2[i + 1][j];
      dp2[i][j] %= MOD;
      dp2[i][next] += dp2[i + 1][j];
      dp2[i][next] %= MOD;
    }
  }
  for (int i = 0; i <= N; i++){
    for (int j = K - 1; j >= 0; j--){
      dp2[i][j] += dp2[i][j + 1];
      dp2[i][j] %= MOD;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++){
    long long cnt = 0;
    for (int j = 0; j <= K; j++){
      cnt += (long long) dp[i][j] * dp2[i + 1][K - j] % MOD;
    }
    cnt %= MOD;
    if (cnt * 2 % MOD == dp[N][K]){
      ans++;
    }
  }
  cout << ans << endl;
}