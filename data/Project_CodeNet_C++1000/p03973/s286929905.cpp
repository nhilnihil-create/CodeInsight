#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = a[0] - 1, res = 2;
  for(int i = 1; i < n; i++){
    ans += (a[i] - 1) / res;
    if(res == a[i]) res++;
  }
  cout << ans << endl;

  return 0;
}
