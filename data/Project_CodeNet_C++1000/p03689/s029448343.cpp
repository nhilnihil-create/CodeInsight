// 見せてやるぜ、奇跡ってやつをよぉ……
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
#define DEBUG_VLL(vec) REP(sz, vec.size()) cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll width, height, w, h;
    cin >> height >> width >> h >> w;
    if (width % w == 0 && height % h == 0) cout << "No\n";
    else {
        cout << "Yes\n";
        vvll ans(height, vll(width, 0));
        if (width % w != 0) {
            for (ll i = 0; i < height; i++) {
                for (ll j = 0; j < width; j += w) {
                    ans[i][j] = 999999999;
                }
            }
            for (ll i = 0; i < height; i++) {
                for (ll j = w - 1; j < width; j += w) {
                    ans[i][j] = -1000000000;
                }
            }
        } else {
            for (ll i = 0; i < width; i++) {
                for (ll j = 0; j < height; j += h) {
                    ans[j][i] = 999999999;
                }
            }
            for (ll i = 0; i < width; i++) {
                for (ll j = h - 1; j < height; j += h) {
                    ans[j][i] = -1000000000;
                }
            }
        }

        REP(i, height) {
            REP(j, width) {
                cout << ans[i][j] << (j == width - 1?'\n':' ');
            }
        }
    }
    return 0;
}
