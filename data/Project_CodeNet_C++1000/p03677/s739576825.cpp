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
#define DEBUG_VLL(vec) REP(sz, vec.size()) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    V<int> imos(m + 2, 0);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) imos[a[i] + 2]++, imos[a[i + 1] + 1]--;
        else imos[a[i] + 2]++, imos[1]++, imos[a[i + 1] + 1]--;
    }
    for (int i = 0; i < m + 1; i++) imos[i + 1] += imos[i];

    // for (int i = 0; i < imos.size(); i++) cout << imos[i] << (i == imos.size() - 1 ? '\n' : ' ');

    vll acca(m + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) acca[a[i + 1]] += (ll)(m - a[i] + a[i + 1] - 1);
        else acca[a[i + 1]] += (ll)(a[i + 1] - a[i] - 1);
    }
    // DEBUG_VLL(acca)

    // x = 1
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            ans += (ll)(a[i + 1]);
        } else {
            ans += (ll)(a[i + 1] - a[i]);
        }
    }

    ll tmp = ans;

    // x = 2~m
    for (int i = 2; i < m + 1; i++) {
        ans -= imos[i];
        ans += acca[i - 1];
        chmin(tmp, ans);
    }

    cout << tmp << '\n';
    return 0;
}
