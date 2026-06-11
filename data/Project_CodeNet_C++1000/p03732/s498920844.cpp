#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, w;
  cin >> n >> w;

  vector<pair<ll, ll>> v_wv(n);
  for (auto &p : v_wv) {
    cin >> p.first >> p.second;
  }

  ll offset = v_wv.front().first;
  array<vector<ll>, 4> vw;
  for (auto &p : v_wv) {
    vw[p.first - offset].push_back(p.second);
  }

  for (auto &v : vw) {
    sort(v.begin(), v.end(), greater<ll>());
  }

  ll ans = 0;
  for (ll i = 0; i <= vw[0].size(); i++) {
    for (ll j = 0; j <= vw[1].size(); j++) {
      for (ll k = 0; k <= vw[2].size(); k++) {
        for (ll l = 0; l <= vw[3].size(); l++) {
          ll sum_v = 0;
          sum_v += accumulate(vw[0].begin(), vw[0].begin() + i, 0ll);
          sum_v += accumulate(vw[1].begin(), vw[1].begin() + j, 0ll);
          sum_v += accumulate(vw[2].begin(), vw[2].begin() + k, 0ll);
          sum_v += accumulate(vw[3].begin(), vw[3].begin() + l, 0ll);
          ll sum_w = offset * i + (offset + 1) * j + (offset + 2) * k +
                     (offset + 3) * l;
          if (sum_w <= w) {
            // cout << i << ' ';
            // cout << j << ' ';
            // cout << k << ' ';
            // cout << l << ' ';
            // cout << "add: " << sum_v << ' ' << sum_w << '\n';
            ans = max(ans, sum_v);
          }
        }
      }
    }
  }

  cout << ans << '\n';
}