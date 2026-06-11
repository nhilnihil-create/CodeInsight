#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using P = pair<ll, int>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<P> fr;
  fr.emplace_back(a[0], 0);
  for (int i = 1; i < n; i++) {
    if (a[i] > fr.back().first) 
      fr.emplace_back(a[i], i);
  }
  vector<ll> res(n), num(fr.size());
  rep(i, n) {
    auto it = lower_bound(fr.begin(), fr.end(), make_pair(a[i], 0));
    if (it->first == a[i])
      num[it-fr.begin()]++;
    else {
      if (it != fr.begin()) {
        auto prev = it;
        prev--;
        res[it->second] += a[i]-prev->first;
        num[prev-fr.begin()]++;
      } else 
        res[0] += a[i];
    }
  }
  for (int i = (int)fr.size()-1; i >= 0; i--) {
    if (i) {
      res[fr[i].second] += num[i]*(fr[i].first-fr[i-1].first);
      num[i-1] += num[i];
    } else
      res[0] += num[0]*a[0];
  }
  rep(i, n)
    cout << res[i] << '\n';
  return 0;
}