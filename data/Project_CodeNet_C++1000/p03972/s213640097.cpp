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

using P = pair<ll, bool>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h;
  cin >> w >> h;
  vector<ll> p(w), q(h);
  rep(i, w) cin >> p[i];
  rep(i, h) cin >> q[i];
  int xnum = 0, ynum = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  rep(i, w) pq.push({p[i], 1});
  rep(i, h) pq.push({q[i], 0});
  ll ans = 0;
  while (!pq.empty()) {
    ll v;
    bool f;
    tie(v, f) = pq.top();
    pq.pop();
    if (f) {
      ans += v*max(h+1-ynum, 0);
      xnum++;
    } else {
      ans += v*max(w+1-xnum, 0);
      ynum++;
    }
  }
  cout << ans << endl;
  return 0;
}