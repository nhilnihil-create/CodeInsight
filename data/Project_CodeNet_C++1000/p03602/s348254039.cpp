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
    vvll a(n, vll(n));
    REP(i, n) REP(j, n) cin >> a[i][j];
    bool is_add = true;
    ll ans = 0;
    REP(i, n) rep(j, i+1, n) {
        is_add = true;
        REP(k, n) {
            if (k==i || k==j) continue;
            if (a[i][j] > a[i][k]+a[k][j]) {
                cout << -1 << '\n'; return 0;
            } else if (a[i][j] == a[i][k]+a[k][j]) {
                is_add = false;
            }
        }
        if (is_add) ans += a[i][j];
    }
    cout << ans << '\n';
    return 0;
}
