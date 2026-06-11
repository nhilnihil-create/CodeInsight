#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> vp1(n), vp2(m);
  for (auto &p : vp1) cin >> p.first >> p.second;
  for (auto &p : vp2) cin >> p.first >> p.second;

  auto dist = [](pair<ll, ll> &a, pair<ll, ll> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
  };

  for (auto &p : vp1) {
    ll min_dist = dist(p, vp2.front());
    int min_idx = 0;
    for (int i = 0; i < m; i++) {
      auto &p2 = vp2[i];
      ll d = dist(p, p2);
      if (d < min_dist) {
        min_dist = d;
        min_idx = i;
      }
    }

    cout << min_idx + 1 << '\n';
  }

  return 0;
}