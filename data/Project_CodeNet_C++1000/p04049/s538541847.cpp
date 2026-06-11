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

ll n, k;
V< V<int> > edges;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    edges.resize(n);
    for (ll i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }

    ll ans = HIGHINF;
    if (k & 1) {
        for (ll i = 0; i < n; i++) {
            for (int j: edges[i]) {
                vll d(n, HIGHINF); d[i] = 0, d[j] = 0;
                queue<int> que; que.push(i), que.push(j);
                while (!que.empty()) {
                    int q = que.front(); que.pop();
                    for (int e: edges[q]) {
                        if (d[e] > d[q] + 1) {
                            d[e] = d[q] + 1;
                            que.push(e);
                        }
                    }
                }

                ll tmp = 0;
                for (ll i = 0; i < n; i++) {
                    if (d[i] > k / 2) tmp++;
                }
                chmin(ans, tmp);
            }
        }
    } else {
        for (ll i = 0; i < n; i++) {
            vll d(n, HIGHINF); d[i] = 0;
            queue<int> que; que.push(i);
            while (!que.empty()) {
                int q = que.front(); que.pop();
                for (int e: edges[q]) {
                    if (d[e] > d[q] + 1) {
                        d[e] = d[q] + 1;
                        que.push(e);
                    }
                }
            }

            ll tmp = 0;
            for (ll i = 0; i < n; i++) {
                if (d[i] > k / 2) tmp++;
            }
            chmin(ans, tmp);
        }
    }
    cout << ans << '\n';
    return 0;
}
