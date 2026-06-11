#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  ll Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;

  ll q1=Q*4, h1=H*2, s1=S;
  ll q2=Q*8, h2=H*4, s2=S*2, d2=D;
  ll min1 = min({q1, h1, s1});
  ll min2 = min({q2, h2, s2, d2});
  ll ans = min2 * (N / 2); N %= 2;
  if (N == 1) ans += min1;

  cout << ans << endl; 
  return 0;
}
