#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

vvll edges;

ll dfs(ll i) {
    ll cs = edges[i].size();
    vll cls;
    for (ll to: edges[i]) cls.push_back(dfs(to));
    sort(cls.begin(), cls.end());
    ll ret = 0;
    REP(j, cls.size()) {
        chmax(ret, cls[j]+cs-j);
    }
    return ret;
} 

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    edges.resize(n+1);
    rep(i, 2, n+1) {
        ll a; cin >> a;
        edges[a].push_back(i);
    }
    cout << dfs(1) << '\n';
    return 0;
}
