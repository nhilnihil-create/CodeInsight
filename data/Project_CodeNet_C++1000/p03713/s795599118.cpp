#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
const ll INF = 1e15;

ll diff(ll a, ll b, ll c) { return max(a, max(b, c)) - min(a, min(b, c)); }

int main() {
  ll h, w;
  cin >> h >> w;

  ll ans = INF;

  FOR(i, 1, w) {
    ll a = i * h;
    ll b = h * ((w - i) / 2);
    ll c = h * (w - i - (w - i) / 2);
    ans = min(ans, diff(a, b, c));
  }

  FOR(i, 1, h) {
    ll a = i * w;
    ll b = w * ((h - i) / 2);
    ll c = w * (h - i - (h - i) / 2);
    ans = min(ans, diff(a, b, c));
  }

  FOR(i, 1, w) {
    ll a = i * h;
    ll b = (w - i) * (h / 2);
    ll c = (w - i) * (h - h / 2);
    ans = min(ans, diff(a, b, c));
  }

  FOR(i, 1, h) {
    ll a = i * w;
    ll b = (h - i) * (w / 2);
    ll c = (h - i) * (w - w / 2);
    ans = min(ans, diff(a, b, c));
  }

  cout << ans << endl;
  return 0;
}