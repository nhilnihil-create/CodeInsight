#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll H,W;cin >> H >> W;
  ll ans = 10000000000;
  for(int bit=0;bit<2;bit++){
    if(bit == 1){
      ll tmp = H;
      H = W;
      W = tmp;
    }
    for(ll h=1;h<H;h++){ 
      ll A = h*W;
      ll B = (W/2)*(H-h);
      ll C = H*W - A - B;
      ll D = max(max(A,B),C) - min(min(A,B),C);
      ans = min(ans,D);
      B = (H-h)/2*W;
      C = H*W - A - B;
      D = max(max(A,B),C) - min(min(A,B),C);
      ans = min(ans,D);
    }
  }
  cout << ans << endl;
}