#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  ll h, w;
  cin >> h >> w;

  if (h % 3 == 0 || w % 3 == 0) cout << 0 << endl;
  else {
    ll ans = min(h, w);
    FOR(i, 1, w) {
      vector<ll> s(3);
      s[0] = h / 2 * i;
      s[1] = (h - h / 2) * i;
      s[2] = h * (w - i);
      sort(s.begin(), s.end());
      ans = min(ans, s[2] - s[0]);
    }

    FOR(i, 1, h) {
      vector<ll> s(3);
      s[0] = w / 2 * i;
      s[1] = (w - w / 2) * i;
      s[2] = w * (h - i);
      sort(s.begin(), s.end());
      ans = min(ans, s[2] - s[0]);
    }
    cout << ans << endl;
  }


  
  return 0;
}