#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, c, k;
  cin >> n >> c >> k;
  vector<ll> t(n);
  rep(i, n) cin >> t[i];
  sort(t.begin(), t.end());
  vector<bool> done(n, false);
  ll cnt = 0;
  rep(i, n) {
    if (done[i]) continue;
    ll idx = i;
    ll departure = t[idx] + k;
    ll capacity = c;
    while (t[idx] <= departure && capacity != 0) {
      done[idx] = true;
      capacity--;
      idx++;
      if (idx >= n) break;
    }
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
