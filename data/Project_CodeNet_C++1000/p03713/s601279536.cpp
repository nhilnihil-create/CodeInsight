#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll H,W;
  cin >> H >> W;
  ll ans = H * W;
  vector<ll> s(3);
  for(int i = 0; i < 2; i++){
    for(ll h = 1; h < H; h++){
      //縦割り
      s.at(0) = h * W;
      s.at(1) = (H-h) * (W/2);
      s.at(2) = H * W - (s.at(0) + s.at(1));
      sort(s.begin(),s.end());
      ans = min(ans, s.at(2) - s.at(0));
      
      //横割り
      s.at(0) = h * W;
      s.at(1) = ((H-h) / 2) * W;
      s.at(2) = H * W - (s.at(0) + s.at(1));
      sort(s.begin(),s.end());
      ans = min(ans, s.at(2) - s.at(0));
      
    }
    swap(H,W);
  }
  cout << ans << endl;
    
}