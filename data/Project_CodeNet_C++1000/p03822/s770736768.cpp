#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  vector<vector<int>> a(n+1);
  for(int i = 2; i <= n; i++){
    int x; cin >> x;
    a[x].push_back(i);
  }

  vector<int> dp(n+1, 1);
  function< void(int) > dfs =
  [&](int u){
    vector<int> vec;
    for(int v : a[u]){
      dfs(v);
      vec.push_back(dp[v]);
    }
    sort(vec.rbegin(),vec.rend());
    for(int i = 0; i < vec.size(); i++){
      dp[u] = max(dp[u], vec[i] + i+1);
    }
    return;
  };
  dfs(1);
  cout << dp[1]-1 << endl;

  return 0;
}
