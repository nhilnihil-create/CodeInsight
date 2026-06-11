#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll w, h, n;
  cin >> w >> h >> n;
  ll W = 0, H = 0;
  for (ll i = 0; i < n; i++) {
    ll x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      if (W < x) W = x;
    }
    if (a == 2) {
      if (w > x) w = x;
    }
    if (a == 3) {
      if (H < y) H = y;
    }
    if (a == 4) {
      if (h > y) h = y;
    }
  }
  if ((w-W)< 0 || (h-H) < 0) {
    cout << 0 << '\n';
    return 0;
  }
  cout << (w-W)*(h-H) << '\n';
}