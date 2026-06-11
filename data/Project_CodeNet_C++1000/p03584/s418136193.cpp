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
    ll n, k; cin >> n >> k;
    vll a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];
    ll ans = 0;
    REP(i, n) if ((a[i]&k) == a[i]) ans += b[i];

    for (ll i=1; i<=k; i<<=1) {
        if (k&i) {
            k ^= i;
            ll tmp=0;
            REP(j, n) if ((a[j]&k) == a[j]) tmp += b[j];
            chmax(ans, tmp);
        }
        k^=i;
    }
    cout << ans << '\n';
    return 0;
}
