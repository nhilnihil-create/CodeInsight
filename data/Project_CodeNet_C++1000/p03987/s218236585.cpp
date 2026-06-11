#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  vector<int> a(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  vector<int> idx(n+1);
  for(int i = 1; i <= n; i++){
    idx[a[i]] = i;
  }

  set<int> st = {0, n+1};
  int ans = 0;
  for(int i = 1; i <= n; i++){
    auto pos = st.lower_bound(idx[i]);
    int right = *pos, left = *(--pos);
    ans += i * (idx[i] - left) * (right - idx[i]);
    st.insert(idx[i]);
  }
  cout << ans << endl;

  return 0;
}
