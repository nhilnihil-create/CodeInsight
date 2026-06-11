#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  map<int,int> mp;
  for(int i = 0; i < n; i++){
    int a,b; cin >> a >> b;
    mp[a] = b;
  }

  auto p1 = *mp.begin();
  auto p2 = *mp.rbegin();
  //int ans = p2.first + min(p2.second, p1.second - p2.second);
  int ans = p2.first + p2.second;
  cout << ans << endl;

  return 0;
}
