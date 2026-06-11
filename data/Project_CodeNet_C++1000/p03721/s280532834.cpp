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
  ll n, k;
  cin >> n >> k;
  vector<pair<ll,ll>> a(n);
  for (ll i = 0; i < n; i++) {
    ll p, q;
    cin >> p >> q;
    a[i] = make_pair(p,q);
  }
  Sort(a);
  ll cnt = 0;
  for (ll i = 0; ; i++) {
    cnt += a[i].second;
    if (cnt >= k) {
      cout << a[i].first << '\n';
      return 0;
    }
  }
}