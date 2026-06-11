#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  const ll INF = 100000008*4;
  vector<P> s(n), p(m), ans(n, make_pair(0,INF));
  rep(i,n) {
    int a, b; cin >> a >> b;
    s[i] = make_pair(a,b);
  }
  rep(i,m) {
    int c, d; cin >> c >> d;
    p[i] = make_pair(c,d);
  }
  rep(i,n) {
    ll x1 = s[i].first;
    ll y1 = s[i].second;
    rep(j,m) {
      ll x2 = p[j].first;
      ll y2 = p[j].second;
      ll d = abs(x1 - x2) + abs(y1 - y2);
      if (ans[i].second > d) {
        ans[i].first = j+1;
        ans[i].second = d;
      }
    }
  }
  rep(i,n) {
    cout << ans[i].first << endl;
  }

  return 0;
}