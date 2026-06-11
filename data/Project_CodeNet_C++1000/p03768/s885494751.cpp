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
    ll n, m; cin >> n >> m;
    vvll edges(n);
    REP(i, m) {
        ll a, b; cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    ll q; cin >> q;
    vll v(q), d(q), c(q);
    REP(i, q) {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }

    vll col(n, 0), ddd(n, -1);
    for (ll i=q-1; i>=0; i--) {
        // v[i] から距離 d[i] まで塗られているなら上書きはない
        if (ddd[v[i]] >= d[i]) continue;

        ll tmpd = d[i];
        queue<ll> node;
        node.push(v[i]);
        while (tmpd >= 0 && !node.empty()) {
            queue<ll> nnode;
            while (!node.empty()) {
                q = node.front(); node.pop();
                if (ddd[q] >= tmpd) continue;
                ddd[q] = tmpd;
                if (col[q] == 0) col[q] = c[i];
                for (ll e: edges[q]) {
                    if (ddd[e] < tmpd - 1) nnode.push(e);
                }
            }
            node = nnode;
            tmpd--;
        }
    }

    REP(i, n) {
        cout << col[i] << '\n';
    }
    return 0;
}
