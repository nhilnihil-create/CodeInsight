#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
using P = pair<int, int>;

signed main(){

  int h, w; cin >> h >> w;
  priority_queue<P,vector<P>,greater<P>> q; //最小値
  for(int i = 0; i < h; i++){
    int p; cin >> p;
    q.push({p, 0});
  }
  for(int i = 0; i < w; i++){
    int p; cin >> p;
    q.push({p, 1});
  }

  int ans = 0, x = w+1, y = h+1;
  while(!q.empty()){
    auto p = q.top(); q.pop();
    if(p.second == 0){
      ans += x * p.first;
      y--;
    }else {
      ans += y * p.first;
      x--;
    }
  }
  cout << ans << endl;

  return 0;
}
