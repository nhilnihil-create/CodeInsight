#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n;
  cin >> n;
  vector<pair<ll, ll> > a(n);
  rep(i, 0, n) cin >> a[i].first >> a[i].second;
  sort(all(a));
  ll ans = (a[0].first-1) + (a[n-1].first-a[0].first+1) + (a[n-1].second-0);
  cout << ans << "\n";
}