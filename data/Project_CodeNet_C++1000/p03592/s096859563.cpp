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
  ll n, m, k;
  cin >> n >> m >> k;
  for (ll i = 0; i <= m; i++) {
    ll ans = n*i;
    for (ll j = 0; j <= n; j++) {
      ll c = ans + (m-i)*j -i*j;
      if (c == k) {
        cout << "Yes" << '\n';
        return 0;
      }
    }
  }
  cout << "No" << '\n';
}