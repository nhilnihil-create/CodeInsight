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
    ll n, m; cin >> n >> m;
    vvll a(n, vll(m, 0));
    REP(i, n) REP(j, m) {cin >> a[i][j]; a[i][j]--;}

    ll ans = HIGHINF;
    V<bool> use_sports(m, true);
    REP(_, m-1) {
        vll num_sports(m, 0);
        REP(i, n) REP(j, m) {
            if (use_sports[a[i][j]]) {
                num_sports[a[i][j]]++;
                break;
            }
        }
        ll maxa=0, maxi=-1;
        REP(i, m) {
            if (num_sports[i] > maxa) {
                maxa = num_sports[i]; maxi = i;
            }
        }
        chmin(ans, maxa);
        use_sports[maxi] = 0;
    }
    if (n==1) cout << 1 << endl;
    else if (m==1) cout << n << endl;
    else cout << ans << endl;
    return 0;
}
