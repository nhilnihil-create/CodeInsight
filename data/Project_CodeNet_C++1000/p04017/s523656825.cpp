#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  vector<int> x(n);
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  int l, q; cin >> l >> q;

  static int dp[100001][40];
  for(int i = 0; i < n; i++){
    int pos = upper_bound(x.begin(),x.end(),x[i] + l) - x.begin() - 1;
    dp[i][0] = pos;
  }
  for(int k = 0; k < 30; k++){
    for(int i = 0; i < n; i++){
      dp[i][k+1] = dp[dp[i][k]][k];
    }
  }

  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    if(a > b) swap(a, b);
    int ans = 0;
    for(int k = 30; k >= 0; k--){
      if(dp[a][k] < b){
        a = dp[a][k];
        ans += 1 << k;
        if(b <= a) break;
      }
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
