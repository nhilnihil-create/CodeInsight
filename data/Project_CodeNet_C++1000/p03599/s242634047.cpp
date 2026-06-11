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
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    int ansu = 0, ansd = 1;
    for (int ai = 0; ai <= f / (100 * a); ai++) {
        for (int bi = 0; bi <= (f - 100 * a * ai) / (100 * b); bi++) {
            for (int ci = 0; ci <= (f - 100*a*ai - 100*b*bi) / c; ci++) {
                for (int di = 0; di <= (f - 100*a*ai - 100*b*bi - c*ci) / d; di++) {
                    if ((ai * a + bi * b) * e < c * ci + d * di) break;
                    int tmpu = c * ci + d * di, tmpd = 100 * a * ai + 100 * b * bi + c * ci + d * di;
                    if (ansu * tmpd < ansd * tmpu) {
                        // cout << tmpu << ' ' << tmpd << '\n';
                        ansu = tmpu, ansd = tmpd;
                    }
                }
            }
        }
    }

    if (ansu == 0) ansd = 100 * min(a, b);
    cout << ansd << ' ' << ansu << '\n';
    return 0;
}
