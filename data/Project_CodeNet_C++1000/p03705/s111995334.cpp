#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b; cin >> n >> a >> b;
  ll l = a * (n-1) + b;
  ll r = b * (n-1) + a;
  ll ans = r - l + 1;
  //cout << l << " " << r << " " << ans << endl;
  if (ans < 0) ans = 0;
  if (a > b) ans = 0;
  cout << ans << endl;
  return 0;
}
