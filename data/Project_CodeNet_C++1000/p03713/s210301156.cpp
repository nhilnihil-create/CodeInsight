#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

ll h, w, h1, h2, h3, w1, w2, w3, mx, mn, ans = INF, m1, m2, m3;

ll f(ll h, ll w) {
    for (ll h1 = 1; h1 < h; ++h1) {
    m1 = h1 * w;

    h2 = ceil((h - h1) / 2.0);

    m2 = h2 * w;
    h3 = (h - h1 - h2);
    m3 = h * w - m1 - m2;
    mx = max({m1, m2, m3});
    mn = min({m1, m2, m3});
    ans = min(ans, mx - mn);

    h2 = h - h1;
    w2 = ceil(w / 2.0);
    m2 = h2 * w2;
    w3 = w - w2;
    m3 = h * w - m1 - m2;
    mx = max({m1, m2, m3});
    mn = min({m1, m2, m3});
    ans = min(ans, mx - mn);
  }
  return ans;
}


int main() {
  int H, W;
  cin >> H >> W;
  ans = min(f(H, W), f(W, H));

  cout << ans << endl;
  return 0;
}
