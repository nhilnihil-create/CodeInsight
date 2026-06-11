#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

ll dp[56][56][2506];

int main(){

  int n,a;
  int x[56];
  int i,j,k,s;
  int sum = 0;
  ll ans = 0;

  scanf("%d %d", &n ,&a);
  for(i = 1;i <= n;i++){
    scanf("%d", &x[i]);
    sum += x[i];
  }

  for(j = 0;j <= 50;j++){
    for(k = 0;k <= 50;k++){
      for(s = 0;s <= 2500;s++) dp[j][k][s] = 0;
    }
  }

  for(i = 0;i <= n;i++) dp[i][0][0] = 1;
  for(j = 1;j <= n;j++){
    for(k = 1;k <= j;k++){
      for(s = 1;s <= sum;s++){
        if(s < x[j]) dp[j][k][s] = dp[j - 1][k][s];

        else {
          dp[j][k][s] = dp[j - 1][k - 1][s - x[j]] + dp[j - 1][k][s];
        }
      }
    }
  }

  for(i = 1;i <= n;i++){
    ans += dp[n][i][i*a];
  }

  printf("%lld\n", ans);

  return 0;
}
