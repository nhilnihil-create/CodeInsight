#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int W, H; cin >> W >> H;
  vector<P> a(W + H);
  for (int i = 0; i < W + H; i++) {
    int x; cin >> x;
    a[i] = {x, (i < W)};
  }
  sort(begin(a), end(a));
  ll ans {};
  int c[2] { W + 1, H + 1 };
  for (auto x : a) {
    ans += (ll)x.first * c[x.second];
    c[!x.second]--;
  }
  cout << ans << endl;
  return 0;
}
