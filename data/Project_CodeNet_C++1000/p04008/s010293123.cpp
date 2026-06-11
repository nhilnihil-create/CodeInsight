#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n,k; cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }

  vector<vector<int>> G(n);
  for(int i = 0; i < n; i++){
    if(i > 0) G[a[i]].push_back(i);
  }

  int ans = 0;
  vector<int> dp(n,0);
  function< void(int,int) > dfs =
  [&](int u,int pre){
    for(int v : G[u]){
      if(v == pre) continue;
      dfs(v,u);
      dp[u] = max(dp[u],dp[v] + 1);
    }
    if(dp[u]+1 == k){
      dp[u] = -1;
      if(u != 0 && pre != 0) ans++;
    }
  };
  dfs(0,-1);
  cout << ans + (a[0] != 0) << endl;

  return 0;
}
