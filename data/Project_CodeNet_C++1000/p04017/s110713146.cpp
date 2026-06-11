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
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  vll x(n); REP(i, n) cin >> x[i];
  ll l, q; cin >> l >> q;
  vvll doubling(n, vll(31, 0));
  ll j;
  REP(i, n) {
    ll left=i, right=n;
    while (left<right) {
      ll mid = (left+right) / 2;
      if (x[mid]-x[i] <= l) left=mid+1;
      else right=mid;
    }
    doubling[i][0] = left-1;
  }

  REP(j, 30) {
    REP(i, n) {
      doubling[i][j+1] = doubling[doubling[i][j]][j];
    }
  }

  REP(_, q) {
    ll a, b; cin >> a >> b; a--; b--;
    if (a > b) swap(a, b);
    ll ans = 0;
    for (ll i=30; i>=0; i--) {
      if (doubling[a][i] < b) {
        ans += 1<<i;
        a = doubling[a][i];
      }
    }
    cout << ans+1 << '\n';
  }

  return 0;
}
