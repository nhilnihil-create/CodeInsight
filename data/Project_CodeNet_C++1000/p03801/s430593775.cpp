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

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    V<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    V<int> ord(n); iota(ALL(ord), 0);
    sort(ALL(ord), [&](int i, int j) {
        if (a[i] == a[j]) return i > j;
        else return a[i] > a[j];
    });

    vll ans(n, 0);
    int mini = ord[0];
    for (ll i = 1; i < n; i++) {
        ans[mini] += i * (ll)(a[ord[i - 1]] - a[ord[i]]);
        chmin(mini, ord[i]);
    }
    ans[mini] += (ll)n * (ll)a[ord.back()];

    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    return 0;
}
