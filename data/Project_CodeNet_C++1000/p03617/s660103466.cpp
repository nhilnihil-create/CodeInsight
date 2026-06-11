#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  
  int64_t ans, one;
  one = min(S, min(2*H, 4*Q));
  ans = N/2*min(D, one*2)+N%2*one;
  
  cout << ans << endl;
}