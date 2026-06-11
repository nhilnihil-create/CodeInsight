#include<stdio.h>

const int INF = 1000000;

int min(int a, int b){
  return a > b ? b : a;
}

int main(){
  int N, Ma, Mb;
  scanf("%d %d %d", &N, &Ma, &Mb);
  
  int a[N];
  int b[N];
  int c[N];
  for(int i = 0; i < N; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
  
  int dp[N + 1][401][401];
  for(int i = 0; i <= N; i++){
    for(int ma = 0; ma <= 400; ma++){
      for(int mb = 0; mb <= 400; mb++){
        dp[i][ma][mb] = INF;
      }
    }
  }
  dp[0][0][0] = 0;
  
  for(int i = 0; i < N; i++){
    for(int ma = 0; ma <= 400; ma++){
      for(int mb = 0; mb <= 400; mb++){
        dp[i + 1][ma][mb] = min(dp[i][ma][mb], dp[i + 1][ma][mb]);
        if(ma + a[i] <= 400 && mb + b[i] <= 400){
          dp[i + 1][ma + a[i]][mb + b[i]] = min(dp[i][ma][mb] + c[i], dp[i][ma + a[i]][mb + b[i]]);
        }
      }
    }
  }
  
  int cost = INF;
  for(int ma = 1; ma <= 400; ma++){
    for(int mb = 1; mb <= 400; mb++){
      if(ma * Mb == mb * Ma) cost = min(dp[N][ma][mb], cost);
    }
  }
  
  if(cost < INF) printf("%d\n", cost);
  else puts("-1");
  
  return 0;
}