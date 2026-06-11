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

vvll edges;

ll dfs(ll i, ll p) {
    ll ret = 0;
    for (ll e: edges[i]) {
        if (e == p) continue;
        ret ^= dfs(e, i) + 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    edges.resize(n);
    REP(i, n - 1) {
        ll x, y; cin >> x >> y;
        edges[x - 1].emplace_back(y - 1);
        edges[y - 1].emplace_back(x - 1);
    }

    ll grun = dfs(0, -1);
    if (grun == 0) cout << "Bob\n";
    else cout << "Alice\n";
    return 0;
}
