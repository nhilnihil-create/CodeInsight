#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF (1<<30);

ll get_min(ll h, ll w) {
  ll y = INF;
  for (int x = 1; x <= w-2; x++) {
    ll s1 = x * h;
    ll s2, s3;
    if (w-x % 2 == 0) {
      s2 = s3 = h * ((w-x) / 2);
    } else {
      s2 = h * ((w-x) / 2);
      s3 = h * (1 + (w-x) / 2);
    }

    ll t2, t3;
    if (h % 2 == 0) {
      t2 = t3 = (h / 2) * (w-x);
    } else {
      t2 = (h / 2) * (w-x);
      t3 = (1 + h / 2) * (w-x);
    }

    ll d1 = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
    ll d2 = max(s1, max(t2, t3)) - min(s1, min(t2, t3));
    y = min(y, min(d1, d2));
  }

  return y;
    
}

int main() {
  ll H, W; cin >> H >> W;
  if (H % 3 == 0 || W % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (H == 2 && W == 2) {
    cout << 1 << endl;
    return 0;
  }

  ll ans = min(get_min(H, W), get_min(W, H));
  cout << ans << endl;

  return 0;
}
