#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = n-1; i >= 0; --i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,w;
  cin >> n >> w;
  
  const int wm = 3*n+1;
  vector<vector<int>> dp(n+1,vector<int>(wm+1,-1));
  int w0,v0;
  cin >> w0 >> v0;
  dp[0][0] = 0;
  if(w0<=w) dp[1][0] = v0;
  rep(_,n-1){
    int wi,vi;
    cin >> wi >> vi;
    wi -= w0;
    rep(i,n)rep(j,wm+1){
      if(dp[i][j]<0) continue;
      if(w0*(i+1)+j+wi>w) continue;
      dp[i+1][j+wi] = max(dp[i+1][j+wi],dp[i][j]+vi);
    }
  }
  int ans = 0;
  rep(i,n+1)rep(j,wm+1) ans = max(ans,dp[i][j]);
  cout << ans << endl;
}