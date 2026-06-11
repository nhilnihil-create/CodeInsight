#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<pair<ll, ll>> vp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i].first >> vp[i].second;
  }

  pair<ll, ll> cur{vp[0].first, vp[0].second};
  for (auto &p : vp) {
    ll l = 1, r = pow(10, 18) / max(p.first, p.second);
    while (l < r) {
      ll mid = (l + r) / 2;
      ll fst = p.first * mid, snd = p.second * mid;
      if (cur.first > fst || cur.second > snd) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    cur.first = r * p.first;
    cur.second = r * p.second;
  }

  cout << cur.first + cur.second << '\n';
}