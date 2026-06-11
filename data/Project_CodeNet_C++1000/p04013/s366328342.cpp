#include<stdio.h>

int main(){
  int N, A;
  scanf("%d %d", &N, &A);
  
  int x[N];
  for(int i = 0; i < N; i++) scanf("%d", x + i);
  
  long long dp[N + 1][N * A + 1][N + 1];
  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= N * A; j++){
      for(int k = 0; k <= N; k++){
        dp[i][j][k] = 0;
      }
    }
  }
  
  dp[0][0][0] = 1;
  for(int i = 0; i < N; i++){
    for(int j = 0; j <= N * A; j++){
      for(int k = 0; k <= N; k++){
        if(k > 0 && j - x[i] >= 0){
          dp[i + 1][j][k] += dp[i][j - x[i]][k - 1];
        }
        dp[i + 1][j][k] += dp[i][j][k];
      }
    }
  }
  
  long long cnt = 0;
  for(int j = 0; j <= N * A; j++){
    for(int k = 1; k <= N; k++){
      if(k * A == j) cnt += dp[N][j][k];
    }
  }
  
  printf("%lld", cnt);
  
  return 0;
}