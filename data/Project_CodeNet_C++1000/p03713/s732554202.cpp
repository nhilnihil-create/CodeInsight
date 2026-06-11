#include<bits/stdc++.h>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
using namespace std;
typedef long long ll;

int main(void) {
  int h, w;
  cin >> h >> w;

  if (h % 3 == 0 || w % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (h > w) swap(h, w);

  ll ans = 1001001001;

  for (int i = 1; i <= w - 1; i++) {
    ll sq1 = (ll) i * h;
    ll sq2, sq3;
    if (h % 2 == 0 || (w - i) % 2 == 0) {
      sq2 = (ll) h * (w - i) / 2;
      sq3 = (ll) h * (w - i) / 2;
      ans = min(ans, abs(sq1 - sq2));
    }
    else {
      ll nowH = h;
      ll nowW = w - i;
      if (nowH > nowW) swap(nowW, nowH);
      sq2 = (ll) nowH * (nowW / 2);
      sq3 = (ll) nowH * (nowW / 2 + 1);
      ans = min(ans, max({sq1, sq2, sq3}) - min({sq1, sq2, sq3}));
    }
  }

  for (int i = 1; i <= h - 1; i++) {
    ll sq1 = (ll) i * w;
    ll sq2, sq3;
    if ((h - i) % 2 == 0 || w % 2 == 0) {
      sq2 = (ll) w * (h - i) / 2;
      ans = min(ans, abs(sq1 - sq2));
    }
    else {
      ll nowH = h - i;
      ll nowW = w;
      if (nowH > nowW) swap(nowW, nowH);
      sq2 = (ll) nowH * (nowW / 2);
      sq3 = (ll) nowH * (nowW / 2 + 1);
      ans = min(ans, max({sq1, sq2, sq3}) - min({sq1, sq2, sq3}));
    }
  }

  cout << ans << endl;
  return 0;
}
