#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(void)
{
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  ll ans = 0;
  ll a2, d;
  REP(i, n - 1) {
    a2 = a[i] + a[i + 1];
    if(a2 > x) {
      d = a2 - x;
      if(d > a[i + 1]) {
	a[i] -= d - a[i + 1];
	a[i + 1] = 0;
      } else {
	a[i + 1] -= d;
      }
      ans += d;
    }
  }
  cout << ans << endl;
}
