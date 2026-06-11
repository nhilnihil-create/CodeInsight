#include <iostream>

#define ll long long
#define INF 100000000000000

using namespace std;

ll calc(ll H, ll W) {
  ll s1, s2, s3;
  ll mxs, mns;
  ll res = INF;
  for (int i = 1; i < H; i++) {
    s1 = i * W;
    s2 = (H - i) * (W / 2);
    s3 = (H - i) * (W - (W / 2));
    mxs = max(s1, max(s2, s3));
    mns = min(s1, min(s2, s3));
    res = min(res, mxs - mns);
  }

  s1 = (H / 3) * W;
  s2 = (H - (H / 3) * 2) * W;
  res = min(res, abs(s1 - s2));

  return res;
}

int main() {
  ll H, W;
  cin >> H >> W;

  ll ans = min(H, W);
  ans = min(ans, calc(H, W));
  ans = min(ans, calc(W, H));

  cout << ans << endl;
}
