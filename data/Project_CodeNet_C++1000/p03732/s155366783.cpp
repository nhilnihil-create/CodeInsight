#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n,w; cin >> n >> w;
  vector<vector<int>> v(4);
  int a,b; cin >> a >> b;
  v[0].push_back(b);
  for(int i = 1; i < n; i++){
    int c,d; cin >> c >> d;
    v[c-a].push_back(d);
  }
  for(int i = 0; i < 4; i++){
    sort(v[i].rbegin(),v[i].rend());
  }

  static int dp[4][101];
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < v[i].size(); j++){
      dp[i][j+1] = dp[i][j] + v[i][j];
    }
  }

  int ans = 0;
  for(int i = 0; i <= v[0].size(); i++){
    for(int j = 0; j <= v[1].size(); j++){
      for(int k = 0; k <= v[2].size(); k++){
        for(int l = 0; l <= v[3].size(); l++){
          int weight = a*i + (a+1)*j + (a+2)*k + (a+3)*l;
          if(weight > w) continue;
          int res = dp[0][i] + dp[1][j] + dp[2][k] + dp[3][l];
          ans = max(ans,res);
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
