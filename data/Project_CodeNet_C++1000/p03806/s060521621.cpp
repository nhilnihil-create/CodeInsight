#include <bits/stdc++.h>
using namespace std;
#define N_MAX 40
#define w_MAX 10
#define INF 100000

int dp[N_MAX + 1][w_MAX * (N_MAX + 10) + 1][w_MAX * (N_MAX + 10) + 1];
int a[N_MAX], b[N_MAX], c[N_MAX];

void solve(int N){
  // 初期化
  for (int i = 0; i < N_MAX + 1; i++) {
    for (int j = 0; j < w_MAX * (N_MAX + 10) + 1; j++) {
      for (int k = 0; k < w_MAX * (N_MAX + 10) + 1; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  dp[0][0][0] = 0;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < w_MAX * N_MAX + 1; j++) {
      for (int k = 0; k < w_MAX * N_MAX + 1; k++) {
        dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
      }
    }
  }

}

int main(){
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  
  for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];
  solve(N);
  int ans = INF;
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < w_MAX * N_MAX + 1; j++) {
      for (int k = 1; k < w_MAX * N_MAX + 1; k++) {
        if(j * Mb == k * Ma) ans = min(ans, dp[i][j][k]);
      }
    }
  }
  
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}