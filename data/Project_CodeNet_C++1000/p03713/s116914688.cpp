#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  ll H, W;
  cin >> H >> W;

  ll ans = H * W;
  ll s[3];

  rep(i, 0, 2) {
    rep(h, 1, H) {
      // まずは縦割り
      s[0] = h * W;
      s[1] = (H - h) * (W / 2);
      s[2] = H * W - (s[0] + s[1]);
      sort(s, s + 3);
      ans = min(ans, s[2] - s[0]);

      // 次いで横割り
      s[0] = h * W;
      s[1] = ((H - h) / 2) * W;
      s[2] = H * W - (s[0] + s[1]);
      sort(s, s + 3);
      ans = min(ans, s[2] - s[0]);
    }
    // 板チョコを90度回す
    swap(H, W);
  }

  cout << ans << endl;

  return 0;
}
