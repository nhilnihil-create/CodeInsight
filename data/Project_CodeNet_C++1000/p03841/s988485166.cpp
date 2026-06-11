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
    int n; cin >> n;
    V<int> x(n);
    V<int> ans(n * n, -1);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        ans[--x[i]] = i + 1;
    }

    V<int> ord(n); iota(ALL(ord), 0);
    sort(ALL(ord), [&](int i, int j) {
        return x[i] < x[j];
    });

    int tmpi = 0;
    for (int i: ord) {
        for (int j = 0; j < i; j++) {
            while (ans[tmpi] > -1) tmpi++;
            if (tmpi > x[i]) {
                cout << "No\n";
                return 0;
            }
            ans[tmpi] = i + 1;
        }
    }

    tmpi = n * n - 1;
    reverse(ALL(ord));
    for (int i: ord) {
        for (int j = 0; j < n - i - 1; j++) {
            while (ans[tmpi] > -1) tmpi--;
            if (tmpi < x[i]) {
                cout << "No\n";
                return 0;
            }
            ans[tmpi] = i + 1;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n * n; i++) cout << ans[i] << (i == n * n - 1 ? '\n' : ' ');
    return 0;
}
