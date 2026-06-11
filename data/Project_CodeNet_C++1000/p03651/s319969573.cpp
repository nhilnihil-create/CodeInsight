#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

ll gcd(ll a, ll b){return b==0 ? a : gcd(b, a%b);}

int main()
{
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll g = a[0];
  rep(i, n) g = gcd(g, a[i]);
  rep(i, n) {
    if (a[i] < k) continue;
    ll t = a[i]-k;
    if (t%g == 0) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;

  return 0;
}
