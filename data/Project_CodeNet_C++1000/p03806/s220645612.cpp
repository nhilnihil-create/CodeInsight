#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

ll dp[45][450][450];

int main(){
  int n,ma,mb;
  int a[50],b[50],c[50];
  int i,j,k;
  int suma = 0;
  int sumb = 0;

  scanf("%d %d %d", &n, &ma, &mb);
  for(i = 0;i < n;i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
    suma += a[i];
    sumb += b[i];
  }

  for(i = 0;i <= n;i++){
    for(j = 0;j <= suma;j++){
      for(k = 0;k <= sumb;k++) dp[i][j][k] = 100100100100;
    }
  }

  dp[0][0][0] = 0;
  for(i = 0;i < n;i++){
    for(j = 0;j <= suma;j++){
      for(k = 0;k <= sumb;k++){
        dp[i + 1][j][k] = min(dp[i + 1][j][k],dp[i][j][k]);
        dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]],dp[i][j][k] + c[i]);
      }
    }
  }

  ll ans = 100100100100;

  for(i = 1;i <= suma;i++){
    for(j = 1;j <= sumb;j++){
      if(mb*i == ma*j) ans = min(ans,dp[n][i][j]);
    }
  }

  if(ans == 100100100100) printf("-1\n");

  else printf("%lld\n", ans);

  return 0;
}
