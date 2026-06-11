#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll Q,H,S,D;
  cin >> Q >> H >> S >> D;
  ll N;
  cin >> N;
  N *= 4;
  ll ans = 0;
  ll N2 = N % 8;
   N = N / 8;
  ans += N * min({8*Q,4*H,2*S,D});
   N2 = N2 / 4;
  ans += N2 * min({4*Q,2*H,S});
  cout << ans << endl;
  return 0;
}