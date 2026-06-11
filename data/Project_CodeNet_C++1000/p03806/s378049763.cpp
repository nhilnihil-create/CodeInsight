#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
const int INF = 1e9;
int dp[50][500][500]; 

void init() {
  rep(i,50) rep(j,500) rep(k,500) dp[i][j][k] = INF;
}
 
int main(){
  init();
  int n, Ma, Mb;
  cin >> n >> Ma >> Mb;
  vector<int> a(n), b(n), c(n);

  rep(i,n) cin >> a[i] >> b[i] >> c[i];

  dp[0][0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0 ; j < 400; j++) {
      for (int k = 0; k < 400; k++) {
        dp[i+1][j + a[i]][k + b[i]] = min(dp[i+1][j + a[i]][k + b[i]],dp[i][j][k] + c[i]);
        dp[i+1][j][k] = min(dp[i][j][k],dp[i+1][j][k]);
      }
    }
  }

  int res = INF;
  for (int j = 1; j < 400; j++) {
    for (int k = 1; k < 400; k++) {
      if (Ma * k == Mb * j) res = min(res,dp[n][j][k]);
    }
  }
  if (res == INF) puts("-1");
  else cout << res << endl;
  return 0;
}