#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  ll n, x; cin >> n >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  for (int i=0; i<n-1; i++) {
    ll t = a[i] + a[i+1];
    if (t > x) {
      ll d = t - x;
      a[i+1] = max(0LL, a[i+1]-d);
      a[i] -= max(0LL, d-a[i+1]);
      ans += d;
    }
  }
  cout << ans << endl;

  return 0;
}
