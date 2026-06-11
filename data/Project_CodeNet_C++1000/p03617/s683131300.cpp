#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int Q, H, S, D;
  cin >> Q >> H >> S >> D;

  H = min(Q*2, H);
  S = min(H*2, S);
  D = min(S*2, D);

  int N;
  cin >> N;
  N *= 4;
  
  int ans = 0;
  ans += (N/8) * D;
  N = N%8;
  ans += (N/4) * S;
  N = N%4;
  ans += (N/2) * H;
  N = N%2;
  ans += N * Q;

  cout << ans << endl;

  return 0;
}
