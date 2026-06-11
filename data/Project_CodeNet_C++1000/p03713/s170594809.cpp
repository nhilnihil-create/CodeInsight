#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 10010010010;

int main() {
  ll h, w, a, b, c;
  cin >> h >> w;
  ll ans = INF;
  for (ll i = 1; i < h; i++) {
    a = i * w;
    b = (w / 2) * (h - i);
    c = w * h - a - b;
    ll x = min(min(a, b), c);
    ll y = max(max(a, b), c);
    ans = min(ans, y - x);
    b = (h - i) / 2 * w;
    c = w * h - a - b;
    x = min(min(a, b), c);
    y = max(max(a, b), c);
    ans = min(ans, y - x);
  }
  for (ll j = 1; j < w; j++) {
    a = j * h;
    b = (h / 2) * (w - j);
    c = w * h - a - b;
    ll x = min(min(a, b), c);
    ll y = max(max(a, b), c);
    ans = min(ans, y - x);
    ans = min(ans, w * h - 3 * h * (w / 3));
    b = (w - j) / 2 * h;
    c = w * h - a - b;
    x = min(min(a, b), c);
    y = max(max(a, b), c);
    ans = min(ans, y - x);
  }
  if (h % 3 == 0 || w % 3 == 0) ans = 0;
  cout << ans << endl;
}