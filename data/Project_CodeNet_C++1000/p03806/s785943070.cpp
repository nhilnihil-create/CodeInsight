#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main(){
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<int> a(n), b(n), c(n);
  for(int i=0; i<n; ++i){
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<int>> dp(401,vector<int>(401,INF));
  dp[0][0] = 0;
  for(int i=0; i<n; ++i) for(int j=400; j>=a[i]; --j) for(int k=400; k>=b[i]; --k){
    dp[j][k] =min(dp[j][k], dp[j-a[i]][k-b[i]] + c[i]);
  }
  int ans = INF;
  for(int i=1; i<401; ++i){
    if(i*ma > 400 || i*mb > 400) break;
    ans = min(ans, dp[ma*i][mb*i]);
  }
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}