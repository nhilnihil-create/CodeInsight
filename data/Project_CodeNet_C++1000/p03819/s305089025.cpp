#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <numeric>
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

ll n, m;
vll BIT;
void add(ll a, ll w) {
  for(ll x=a; x<=m; x+=x&-x) BIT[x] += w;
}
ll sum(ll a) {
  ll ret=0;
  for(ll x=a; x>0; x-=x&-x) ret += BIT[x];
  return ret;
}

int main() {
  cin >> n >> m;
  vll l(n), r(n); REP(i, n) cin >> l[i] >> r[i];
  BIT.resize(2*m, 0);
  vll ord(n); iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](ll x, ll y) {
    return r[x]-l[x] < r[y]-l[y];
  });
  ll i = 1;
  rep(d, 1, m+1) {
    while(i<=n && r[ord[i-1]]-l[ord[i-1]]+1==d) {
      add(l[ord[i-1]], 1); add(r[ord[i-1]]+1, -1); i++;
    }
    ll ans = n-i+1;
    for(ll j=d; j<=m; j+=d) ans += sum(j);
    cout << ans << endl;
  }
  return 0;
}
