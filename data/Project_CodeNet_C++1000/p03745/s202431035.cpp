#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    int right1 = i, right2 = i;
    while(right1+1 < n && a[right1] <= a[right1+1]) right1++;
    while(right2+1 < n && a[right2] >= a[right2+1]) right2++;
    i = max(right1, right2);
    ans++;
  }
  cout << ans << endl;

  return 0;
}