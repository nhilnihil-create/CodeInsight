#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<int> odd, even;
  for(int i = 0; i < n; i++){
    if(i%2 == 0){
      even.push_back(a[i]);
    }else {
      odd.push_back(a[i]);
    }
  }
  sort(even.begin(),even.end());
  sort(odd.begin(),odd.end());

  sort(a.begin(),a.end());
  int ans = 0;
  map<int,int> add;
  for(int i = 0; i < even.size(); i++){
    int p = even[i];
    int pos = lower_bound(a.begin(),a.end(),p) - a.begin() + add[p];
    if(pos%2 != 0) ans++;
    add[p]++;
  }
  cout << ans << endl;

  return 0;
}
