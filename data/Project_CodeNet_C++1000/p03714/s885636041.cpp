#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  n *= 3;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  priority_queue<int,vector<int>,greater<int>> q1;
  priority_queue<int> q2;
  vector<int> dp1(n),dp2(n);
  for(int i = 0; i < n*2/3; i++){
    if(i < n/3){
      q1.push(a[i]);
      dp1[i] = a[i] + (i == 0 ? 0 : dp1[i-1]);
    }
    else {
      q1.push(a[i]);
      dp1[i] = dp1[i-1] + a[i] - q1.top(); q1.pop();
    }
  }
  for(int i = n-1; i >= n/3; i--){
    if(n*2/3 <= i){
      q2.push(a[i]);
      dp2[i] = a[i] + (i == n-1 ? 0 : dp2[i+1]);
    }
    else {
      q2.push(a[i]);
      dp2[i] = dp2[i+1] + a[i] - q2.top(); q2.pop();
    }
  }

  int ans = -(1LL << 60);
  for(int i = n/3-1; i < n*2/3; i++){
    ans = max(ans,dp1[i] - dp2[i+1]);
  }
  cout << ans << endl;

  return 0;
}
