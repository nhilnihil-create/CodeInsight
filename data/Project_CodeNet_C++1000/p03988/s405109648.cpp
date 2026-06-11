#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

void fail(){
  cout << "Impossible" << endl;
  exit(0);
}

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int Max = *max_element(a.begin(),a.end());
  vector<bool> used(n, false);
  sort(a.begin(),a.end());
  if(Max % 2 == 0){
    for(int i = Max/2+1; i <= Max; i++){
      int pos = lower_bound(a.begin(),a.end(),i) - a.begin();
      if(pos == n-1 || a[pos] != i || a[pos+1] != i) fail();
      used[pos] = used[pos+1] = true;
    }
    int pos = lower_bound(a.begin(),a.end(),Max/2) - a.begin();
    if(a[pos] != Max/2) fail();
    used[pos] = true;
    for(int i = 0; i < n; i++){
      if(!used[i] && !(Max/2 + 1 <= a[i] && a[i] <= Max)) fail();
    }
  }else {
    for(int i = (Max+1)/2; i <= Max; i++){
      int pos = lower_bound(a.begin(),a.end(),i) - a.begin();
      if(pos == n-1 || a[pos] != i || a[pos+1] != i) fail();
      used[pos] = used[pos+1] = true;
    }
    for(int i = 0; i < n; i++){
      if(!used[i] && !((Max+1)/2 + 1 <= a[i] && a[i] <= Max)) fail();
    }
  }
  cout << "Possible" << endl;

  return 0;
}
