#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll diff(ll h, ll w, ll x) {
  ll res = w * x;
  ll s1, s2, s3, s_min, s_max;

  s1 = w * x; // 2
  s2 = w * ((h - x) / 2);
  s3 = w * h - s1 - s2;
  s_min = min({s1, s2, s3});
  s_max = max({s1, s2, s3});
  res = min(res, s_max - s_min);

  s1 = w * x;
  s2 = (h - x) * (w / 2);
  s3 = w * h - s1 - s2;
  s_min = min({s1, s2, s3});
  s_max = max({s1, s2, s3});
  res = min(res, s_max - s_min);

  return res;
}

int main() {
  ll H, W;
  cin >> H >> W;

  ll ans = H * W;
  ll s1, s2, s3, s_min, s_max;

  for (int h = 1; h <= H - 1; h++)
    ans = min(ans, diff(H, W, h));

  swap(H, W);

  for (int h = 1; h <= H - 1; h++)
    ans = min(ans, diff(H, W, h));

  cout << ans << endl;
}