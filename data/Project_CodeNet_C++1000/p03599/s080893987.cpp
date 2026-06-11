#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<ll> waters, sugars;
  for (int i = 0; 100 * a * i <= f; i++) {
    for (int j = 0; 100 * b * j <= f; j++) {
      ll can_w = 100 * a * i + 100 * b * j;
      if (can_w <= f) waters.push_back(can_w);
    }
  }
  for (int i = 0; c * i <= f; i++) {
    for (int j = 0; d * j <= f; j++) {
      ll can_s = c * i + d * j;
      if (can_s <= f) sugars.push_back(can_s);
    }
  }

  double con = 0;
  ll ans_ws = 0, ans_s = 0;
  for (auto w : waters) {
    for (auto s : sugars) {
      if (s * (100 + e) > (w + s) * e) continue;
      if (w + s == 0 && s > 0) continue;
      if (w + s > f) continue;
      if (ans_s * (w + s) <= s * ans_ws) {
        ans_s = s, ans_ws = w + s;
      }
    }
  }
  cout << ans_ws << " " << ans_s << endl;
  return 0;
}
