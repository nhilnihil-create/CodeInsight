#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<int> dp(10101, 0);
  dp[0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 10000; j >= 0; j--){
      if(j + a[i] > 10000) continue;
      dp[j + a[i]] |= dp[j];
    }
  }

  int ans = 0;
  for(int i = 0; i < 10000; i++){
    if(dp[i] && i % 10 != 0){
      ans = max(ans, i);
    }
  }
  cout << ans << endl;

  return 0;
}