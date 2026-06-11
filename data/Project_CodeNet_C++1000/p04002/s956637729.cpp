#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

signed main(){

  int h,w,n; cin >> h >> w >> n;
  set<pair<int,int>> st,table;
  for(int i = 0; i < n; i++){
    int a,b; cin >> a >> b;
    a--,b--;
    st.insert({a,b});
    for(int dy : {-1,0,1}){
      for(int dx : {-1,0,1}){
        int ny = a + dy;
        int nx = b + dx;
        if(ny-1 < 0 || h <= ny+1 || nx-1 < 0 || w <= nx+1) continue;
        table.insert({ny,nx});
      }
    }
  }

  vector<int> ans(10,0);
  ans[0] = (h-2) * (w-2);
  for(auto p : table){
    int cnt = 0;
    for(int dy : {-1,0,1}){
      for(int dx : {-1,0,1}){
        int ny = p.first + dy;
        int nx = p.second + dx;
        // auto res = lower_bound(st.begin(),st.end(),make_pair(ny,nx));
        // if(res != st.end() && *res.first == ny && *res.second == nx) cnt++;
        cnt += st.count(make_pair(ny,nx));
      }
    }
    //cout << p << " " << cnt << endl;
    ans[cnt]++;
    ans[0]--;
  }

  for(int p : ans){
    cout << p << endl;
  }

  return 0;
}
