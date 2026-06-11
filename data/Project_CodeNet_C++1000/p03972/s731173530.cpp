#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

  int W,H; cin >> W >> H;
  vector<pair<int,int>> v;
  for(int i = 0; i < W+H; i++){
    int p; cin >> p;
    if(i < W) v.push_back({p,0});
    else v.push_back({p,1});
  }
  sort(v.begin(),v.end());

  int ans = 0;
  H++,W++;
  for(int i = 0; i < v.size(); i++){
    if(v[i].second == 0){
      ans += v[i].first * H;
      W--;
    }
    else {
      ans += v[i].first * W;
      H--;
    }
  }
  cout << ans << endl;

  return 0;
}
