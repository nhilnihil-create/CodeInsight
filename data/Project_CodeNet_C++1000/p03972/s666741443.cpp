#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define P pair<ll, ll>

int main() {
  ll w, h;
  cin >> w >> h;
  vector<ll> p(w), q(h);
  rep(i, w) cin >> p[i];
  rep(i, h) cin >> q[i];

  ll ans = 0, res = (w + 1) * (h + 1) - 1, resx = h + 1, resy = w + 1;
  priority_queue<P, vector<P>, greater<P>> pq;
  rep(i, w) pq.push(make_pair(p[i], 0));
  rep(i, h) pq.push(make_pair(q[i], 1));
  while (res > 0) {
    P a = pq.top();
    pq.pop();
    if (a.second == 0) {
      ans += a.first * min(res, resx);
      res -= resx;
      resy--;
    }
    else {
      chmin(resy, res);
      ans += a.first * min(res, resy);
      res -= resy;
      resx--;
    }
  }
  cout << ans << endl;
  




  
  return 0;
}