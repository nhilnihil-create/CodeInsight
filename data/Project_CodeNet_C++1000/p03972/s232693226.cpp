#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int W, H;
int p[100010], q[100010];
vector<pii> v;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> W >> H;
  for (int i = 0; i < W; i++) {
    cin >> p[i];
    v.emplace_back(p[i], 0);
  }
  for (int i = 0; i < H; i++) {
    cin >> q[i];
    v.emplace_back(q[i], 1);
  }
  sort(v.begin(), v.end());
  ll ans = 0, nw = 0, nh = 0;
  for (int i = 0; i < W+H; i++) {
    if (v[i].second == 0) {
      ans += v[i].first * (H+1-nh);
      nw++;
    } else {
      ans += v[i].first * (W+1-nw);
      nh++;
    }
  }
  cout << ans << endl;

  return 0;
}