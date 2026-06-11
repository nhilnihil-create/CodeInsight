#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define show(x) cout << #x << " = " << (x) << endl;
#define show2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define uni(x) x.erase(unique(rng(x)),x.end())
#define SP << " " <<
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int mod = 1000000007;
const double EPS = 1e-9;
const int INF = 1<<30;
const ll INFLL = 1LL<<60;
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main () {
  ll H, W;
  cin >> H >> W;

  auto f = [&](int H, int W) {
    ll ret = INFLL;
    for (ll h = 1; h <= H-1; ++h) {
      ll sa = h*W;
      ll sb = (H-h)/2*W;
      ll sc = (H-h-(H-h)/2)*W;
      ll smax = max({sa,sb,sc});
      ll smin = min({sa,sb,sc});
      ret = min(ret, smax-smin);

      sb = (H-h)*(W/2);
      sc = (H-h)*(W-W/2);
      smax = max({sa,sb,sc});
      smin = min({sa,sb,sc});
      ret = min(ret, smax-smin);
    }
    return ret;
  };

  ll ans;
  ans = min(f(H,W),f(W,H));
  cout << ans << endl;
  return 0;
}