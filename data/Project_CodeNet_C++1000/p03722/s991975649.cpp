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

int n, m;
V< P< P<int, int>, ll> > edges;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.emplace_back(make_pair(a - 1, b - 1), -c);
    }

    vll dist(n, HIGHINF);
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (P< P<int, int>, ll> e: edges) {
            if (dist[e.first.second] > dist[e.first.first] + e.second) dist[e.first.second] = dist[e.first.first] + e.second;
        }
    }

    V<int> loop(n, 0);
    for (int i = 0; i < n; i++) {
        for (P< P<int, int>, ll> e: edges) {
            if (dist[e.first.second] > dist[e.first.first] + e.second) {
                dist[e.first.second] = dist[e.first.first] + e.second;
                loop[e.first.second] = 1;
            }
            if (loop[e.first.first] == 1)  loop[e.first.second] = 1;
        }
    }

    if (loop[n - 1] == 1) cout << "inf\n";
    else cout << -dist[n - 1] << '\n';
    return 0;
}
