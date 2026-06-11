#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
ll INF = 1000000009;
int main()
{
  ll h,w;
  cin >> h >> w;
  if (h % 3 == 0 || w % 3 == 0)
  {
    cout << 0 << "\n";
  }
  else
  {
    ll ans = INF * INF;
    for (ll i = 1; i < h; i++)
    {
      ll x1 = i*w;
      ll x2 = (h - i) * (w / 2);
      ll x3 = (h - i) * (w - w / 2);
      ll y2 = (h - i) / 2 * w;
      ll y3 = ((h - i) - (h - i) / 2) * w;
      ans = min(ans, max(x1, max(x3, x2)) - min(x1, min(x3, x2)));
      ans = min(ans, max(x1, max(y3, y2)) - min(x1, min(y3, y2)));
    }
    for (ll i = 1; i < w; i++)
    {
      ll x1 = i * h;
      ll x2 = (w - i) * (h / 2);
      ll x3 = (w - i) * (h - h / 2);
      ll y2 = (w - i) / 2 * h;
      ll y3 = ((w - i) - (w - i) / 2) * h;
      ans = min(ans, max(x1, max(x3, x2)) - min(x1, min(x3, x2)));
      ans = min(ans, max(x1, max(y3, y2)) - min(x1, min(y3, y2)));
    }
    cout << ans << "\n";
  }
}