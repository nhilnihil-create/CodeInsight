#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int h, w; cin >> h >> w;

  if (h % 3 == 0 || w % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  auto f = [](ll a, ll b) {
    ll res = a * b;
    ll s = a / 2;
    ll t = a % 2 == 0 ? s : s + 1;
    ll l = 0;
    ll u = s * b, d = t * b;
    for (int i = 1; i < b; i++) {
      l += a;
      u -= s;
      d -= t;
      res = min(res, max({abs(l-u), abs(l-d), abs(u-d)}));
    }
    if (b > 2) {
      ll p1, p2, p3;
      p1 = p2 = p3 = b / 3 * a;
      if (b % 3 >= 1) p1 += a;
      if (b % 3 == 2) p2 += a;
      res = min(res, max({abs(p1-p2), abs(p2-p3), abs(p3-p1)}));
    }
    return res;
  };

  cout << min(f(h, w), f(w, h)) << endl;
}