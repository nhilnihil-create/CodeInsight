#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
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
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, ma, mb; cin >> n >> ma >> mb;
    V<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    V<vvll> dp(n + 1, vvll(401, vll(401, HIGHINF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 401; j++) {
            for (int k = 0; k < 401; k++) {
                chmin(dp[i + 1][j][k], dp[i][j][k]);
                if (j + a[i] < 401 && k + b[i] < 401) chmin(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
            }
        }
    }

    ll ans = HIGHINF;
    for (int i = 1; i < 400 / max(ma, mb); i++) {
        chmin(ans, dp[n][i * ma][i * mb]);
    }
    if (ans == HIGHINF) ans = -1;
    cout << ans << '\n';
    return 0;
}
