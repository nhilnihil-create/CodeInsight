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
    ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    if (b > a + d * (n - 1) || b < a - d * (n - 1)) {
        cout << "NO\n";
    } else {
        ll ueue = a, uesi = a, siue = a, sisi = a;
        for (ll i = 1; i < n; i++) {
            // 今の幅
            ueue += d, uesi += c, siue -= c, sisi -= d; 
            if (ueue - (n - i - 1) * c >= b && b >= uesi - (n - i - 1) * d) {
                cout << "YES\n";
                return 0;
            }
            if (sisi + (n - i - 1) * c <= b && b <= siue - (n - i - 1) * d) {
                cout << "YES\n";
                return 0;
            }
        }

        cout << "NO\n";
    }
    return 0;
}
