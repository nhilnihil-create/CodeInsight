#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
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
  ll n, k; cin >> n >> k;
  vll a(n); REP(i, n) cin >> a[i];
  vll asum(n+2, 0), bsum(n+2, 0);
  REP(i, n) {
    asum[i+1] = asum[i] + a[i];
    bsum[i+1] = bsum[i] + max(0LL, a[i]);
  }
  asum[n+1] = asum[n], bsum[n+1] = bsum[n];
  ll ans = 0;
  REP(i, n-k+2) {
    ll bs = bsum[n+1] - (bsum[i+k] - bsum[i]);
    chmax(ans, bs);
    ll ba = bs + asum[i+k] - asum[i];
    chmax(ans, ba);
  }
  cout << ans << endl;
  return 0;
}
