#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> a(N), b(N), c(N);
  for (int i = 0; i < N; i++){
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<int>> dp(401, vector<int>(401, INF));
  dp[0][0] = 0;
  for (int i = 0; i < N; i++){
    for (int j = 400; j >= a[i]; j--){
      for (int k = 400; k >= b[i]; k--){
        dp[j][k] = min(dp[j][k], dp[j - a[i]][k - b[i]] + c[i]);
      }
    }
  }
  int ans = INF;
  for (int i = 1; i <= 400; i++){
    if (Ma * i <= 400 && Mb * i <= 400){
      ans = min(ans, dp[Ma * i][Mb * i]);
    }
  }
  if (ans == INF){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}