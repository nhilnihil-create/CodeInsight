#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;

ll n;

int main() {
  vector<ll> v(4);
  rep (i, 4) {
    cin >> v[i];
  }
  cin >> n;
  n *= 4;
  vector<ll> want(4, 0);
  vector<P> vperL(4);
  rep (i, 4) {
    vperL[i] = make_pair(v[i] * 12 / pow(2, i), i);
  }
  ll ans = 0;
  sort(vperL.begin(), vperL.end());
  rep (i, 4) {
    ans += (n/(ll)pow(2, vperL[i].second)) * v[vperL[i].second];
    n %= (ll)pow(2, vperL[i].second);
  }
  cout << ans << endl;
  return 0;
}
