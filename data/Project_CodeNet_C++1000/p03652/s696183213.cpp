#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
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
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    vvll a(n, vll(m));
    REP(i, n) REP(j, m) {
        cin >> a[i][j];
        a[i][j]--;
    }
    V<bool> used(m, true);
    ll ans = HIGHINF;
    REP(_, m-1) {
        vll nspo(m, 0);
        REP(i, n) REP(j, m) {
            if (used[a[i][j]]) {
                nspo[a[i][j]]++;
                break;
            }
        }
        ll tmp = 0, maxs=0;
        REP(i, m) {
            if (nspo[i] > tmp) {
                tmp = nspo[i];
                maxs = i;
            }
        }
        chmin(ans, tmp);
        used[maxs] = false;
    }
    if (m == 1) cout << n << '\n';
    else cout << ans << '\n';
    return 0;
}
