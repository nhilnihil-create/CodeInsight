#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  ll Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  ll ans = 0;
  
  //2Lの最安値V;
  ll V;
  V = min({8*Q, 4*H, 2*S, D, S+H*2, S+4*Q, S+2*Q+H, 3*H+2*Q, 2*H+4*Q,
          H+6*Q});
  ans += (N/2)*V;
  
  //1Lの最安値v
  ll v;
  v = min({4*Q, 2*H, S, H+2*Q});
  if (N % 2 == 1) {
    ans += v;
  }
  
  cout << ans << endl;
}