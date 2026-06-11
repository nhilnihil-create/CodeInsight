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
  ll n, m;
  cin >> n >> m;
  if (n-m == 0) {
    ll ans = 1;
    for (ll i = 2; i <= n; i++) {
      ans *= i;
      ans %= mod;
    }
    ans = ans*ans%mod*2%mod;
    cout << ans << '\n';
  } 
  else if (abs(n-m) == 1) {
    ll a = max(n,m);
    ll b = min(n,m);
    ll ans = 1;
    for(ll i = 2; i <= b; i++) {
      ans *= i;
      ans %= mod;
    }
    ans = ans*ans%mod*a%mod;
    cout << ans << '\n';
  }
  else {
    cout << 0 << '\n';
  } 
}