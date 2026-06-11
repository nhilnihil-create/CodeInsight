#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;
typedef long long ll;

int main() {
  ll h, w;
  cin >> h >> w;
  ll ans = 1e10;
  for (ll i = 1; i < h; ++i) {
    ll l = min(w*i, w/2*(h-i)), r = max(w*i, (w+1)/2*(h-i));
    ans = min(ans, r-l);
  }
  for (ll i = 1; i < w; ++i) {
    ll l = min(h*i, h/2*(w-i)), r = max(h*i, (h+1)/2*(w-i));
    ans = min(ans, r-l);
  }
  ans = min(ans, min(1LL, h%3) * w);
  ans = min(ans, min(1LL, w%3) * h);
  cout << ans << endl;
  return 0;
}