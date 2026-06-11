#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  ll h, w;
  cin >> h >> w;
  if (h % 3 == 0 || w % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = min(h, w);
  for (ll i = 1LL; i < h; i++) {
    ll j = w / 2;
    ll tmp = max(abs(w * i - j * (h - i)), max(abs(w * i - (w - j) * (h - i)),
                                               abs((w - 2 * j) * (h - i))));
    ans = min(ans, tmp);
  }
  for (ll j = 1LL; j < w; j++) {
    ll i = h / 2;
    ll tmp = max(abs(h * j - i * (w - j)), max(abs(h * j - (h - i) * (w - j)),
                                               abs((h - 2 * i) * (w - j))));
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
