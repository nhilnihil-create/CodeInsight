#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 1LL << 60;
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll n;
  cin >> n;
  vector<ll> a(100010);
  rep(i,n) {
    ll q;
    cin >> q;
    ++a[q];
  }
  ll ans = 1;
  rep(i,100000) {
    ll t = a[i+1]+a[i+2]+a[i];
    ans = max(ans,t);
  }
  cout << ans << '\n';
}
