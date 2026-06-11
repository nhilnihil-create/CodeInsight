#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, c, k; cin >> n >> c >> k;
  vector<int> t(n);
  int ans = 0;
  rep(i,n) cin >> t[i];
  sort(t.begin(), t.end());
  t.push_back(0);
  int train = 0, limit = t[0] + k;
  rep(i,n) {
    if (limit < t[i]) {
      ans++;
      train = 0;
      limit = t[i] + k;
    }
    train++;
    if (train >= c) {
      ans++;
      train = 0;
      limit = t[i+1] + k;
    }
  }
  if (train) ans++;
  cout << ans << endl;
  return 0;
}