#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;
using Pl = pair<ll,ll>;



int main() {
  int n,k; cin >> n >> k;
  vector<ll> a(n);
  vector<ll> v(n+1);
  rep(i,n) {
    cin >> a.at(i);
    v.at(i+1) = a.at(i);
  }
  rep(i,n) {
    v.at(i+1) = max(v.at(i), v.at(i+1));
  }

  ll ans = 1e18;
  rep(bit, 1ll<<n) {
    std::vector<ll> d;
    rep(i,n) {
      if (bit>>i&1) d.push_back(i);
    }
    if (d.size() != k) continue;
    ll maxH = 0, cost = 0;
    for (ll i : d) {
      maxH = max(maxH, v[i]);
      if (a[i] <= maxH) {
        maxH++;
        cost += maxH - a[i];
      } else {
        maxH = a[i];
      }
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}
