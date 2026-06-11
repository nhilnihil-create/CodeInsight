#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

signed main(){

  int n,k; cin >> n >> k;
  vector<int> a(n),b(n);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }

  vector<int> v; //解の候補
  for(int i = 1; i < 30; i++){
    if(k >> i & 1){
      int t = (k ^ (1<<i)) | ((1<<i) - 1);
      v.push_back(t);
    }
  }
  v.push_back(k);

  int ans = 0;
  for(int p : v){
    int res = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < 30; j++){
        if((a[i] >> j & 1) && !(p >> j & 1)) break;
        if(j == 29) res += b[i];
      }
    }
    ans = max(res,ans);
  }
  cout << ans << endl;

  return 0;
}
