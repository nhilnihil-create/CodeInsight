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

ll mypow(ll m, ll p) {
    if (p == 0) return 1;
    ll tmp = mypow(m, p / 2);
    if (p & 1) return tmp * tmp * m;
    else return tmp * tmp;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll tmp = 1;
    ll dig = 0;
    bool is_yes = true;
    for (; dig < 11; dig++) {
        cout << "? " << tmp << endl;
        char c; cin >> c;
        if (c == 'N') {
            is_yes = false;
            break;
        }
        tmp *= 10;
    }
    dig--;

    if (is_yes) {  // 10^p の時
        ll tmp = 9999999999;
        dig = 10;
        for (; dig > 0; dig--) {
            cout << "? " << tmp << endl;
            char c; cin >> c;
            if (c == 'N') {
                break;
            }
            tmp /= 10;
        }
        cout <<  "! " << mypow(10, dig) << endl;
        return 0;
    } else {
        ll low = mypow(10, dig), high = mypow(10, dig + 1);
        while (low < high) {
            ll mid = (low + high) >> 1;
            cout << "? " << mid * 10 << endl;
            char c; cin >> c;
            if (c == 'Y') {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << "! " << low << '\n';
    }
    return 0;
}
