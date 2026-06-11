#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;
  map<ll, ll> mp;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    mp[a] += b;
  }

  ll ans, cnt = 0;
  for (auto x : mp) {
    cnt += x.second;
    if (k <= cnt) {
      ans = x.first;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
