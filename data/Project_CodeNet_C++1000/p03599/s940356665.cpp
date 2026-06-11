#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  set<int> waters;
  for (int i = 0; i <= f; i += a) {
    for (int j = 0; j <= f; j += b) {
      if (i == 0 && j == 0)
        continue;
      if ((i + j) * 100 > f)
        break;
      waters.insert(i + j);
    }
  }

  double concentration = -1;
  int ans1 = 0, ans2 = 0;
  for (auto w : waters) {
    int water = w * 100;
    rep(i, 0, f + 1) {
      rep(j, 0, f + 1) {
        int sugar = i * c + j * d;
        if (water + sugar > f)
          break;
        if (e * w < sugar)
          break;
        double x = 100.0 * sugar / (water + sugar);
        if (concentration < x) {
          concentration = x;
          ans1 = water + sugar;
          ans2 = sugar;
        }
      }
    }
  }
  cout << ans1 << " " << ans2 << endl;
}
