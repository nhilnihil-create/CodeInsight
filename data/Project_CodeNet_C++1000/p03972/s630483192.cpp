#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll w, h; cin >> w >> h;
  V<P<ll, ll> > pq(w+h);
  REP(i, w) {
    ll p; cin >> p;
    pq[i] = make_pair(p, 0);
  }
  REP(i, h) {
    ll q; cin >> q;
    pq[i+w] = make_pair(q, 1);
  }
  sort(pq.begin(), pq.end());
  ll a=w+1, b=h+1;
  ll ans = 0;
  REP(i, w+h) {
    if (pq[i].second == 0) {
      ans += b*pq[i].first; a--;
    } else {
      ans += a*pq[i].first; b--;
    }
  }
  cout << ans << endl;
  return 0;
}
