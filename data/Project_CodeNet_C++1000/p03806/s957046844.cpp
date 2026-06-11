#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const int INF = 1e9;

int dp[41][401][401];

int main(){
  int n,ma,mb;
  cin >> n >> ma >> mb;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> val(n);

  rep(i,n){
    cin >> a[i] >> b[i] >> val[i];
  }
  for (int i = 0;i <= n;i++){
    rep(x,401) rep(y,401) dp[i][x][y] = INF;
  }
  dp[0][0][0] = 0;
  rep(i,n+1){
    rep(x,401){
      rep(y,401){
        if (i == 0) continue;
        if (dp[i-1][x][y] != INF){
            dp[i][x+a[i-1]][y+b[i-1]] = min(dp[i][x+a[i-1]][y+b[i-1]],dp[i-1][x][y] + val[i-1]);
            dp[i][x][y] = min(dp[i][x][y],dp[i-1][x][y]);
        }
      }
    }
    //rep(x,15) {
    //  rep(y,15){
    //    if (dp[i][x][y] == INF) cout << "F ";
    //    else cout << dp[i][x][y] << " ";
    //  }
    //  cout << endl; 
    //}
    //cout << endl;
  }
  
  
  int ans;
  ans = INF;
  rep(i,401) rep(j,401){
    if (i == 0 && j == 0) continue;
    if (mb*i == ma*j) ans = min(ans,dp[n][i][j]);
  }
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  
  return 0;
  
}
