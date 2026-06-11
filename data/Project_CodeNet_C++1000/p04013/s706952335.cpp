#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  int64_t ave;
  cin >> n >> ave;
  int64_t x[n+1];
  x[0]=0;
  for(int i=1; i<=n; i++) cin >> x[i];
  
  int64_t a=n; // x_a番目に書かれた数まで考慮
  int64_t b=n; // 何個取り出すか
  int64_t c=2500LL; // 和のMAX
  int64_t dp[a+1][b+1][c+1];
  
  memset(dp, 0LL, sizeof(dp)); // dp0に初期化
  dp[0][0][0]=1LL; // dp開始条件
  
  for(int i=0; i<=a; i++){
    for(int j=0; j<=b; j++){
      for(int k=0; k<=c; k++){
        if(i>0) dp[i][j][k]+=dp[i-1][j][k];
        if(i>0 && j>0 && k>=x[i]) dp[i][j][k]+=dp[i-1][j-1][k-x[i]];
      }
    }
  }
  
  int64_t ans=0LL;
  for(int i=1; i<=n; i++) ans += dp[n][i][ave*i];
  cout << ans << endl;
}