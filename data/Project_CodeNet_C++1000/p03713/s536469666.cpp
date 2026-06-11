#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

ll h, w, h2, h3, w2, w3, m1, m2, m3, mx, mn, ans = INF, H, W;

ll f(ll h, ll w) {
  for (int i = 1; i < h; ++i) {
    m1 = i * w;

    h2 = (h - i) / 2;
    m2 = h2 * w;
    m3 = h * w - m1 - m2;
    mx = max({m1, m2, m3});
    mn = min({m1, m2, m3});
    ans = min(ans, mx - mn);

    w2 = w / 2;
    m2 = (h - i) * w2;
    m3 = h * w - m1 - m2;
    mx = max({m1, m2, m3});
    mn = min({m1, m2, m3});
    ans = min(ans, mx - mn);
  }
  return ans;
}

int main() {
  cin >> H >> W;

  cout << min(f(H, W), f(W, H)) << endl;

  return 0;
}
