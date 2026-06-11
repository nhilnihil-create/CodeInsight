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
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    V< P<ll, ll> > a = {{0, 0}};
    REP(i, n) {
        ll _a; cin >> _a;
        a.push_back(make_pair(_a, i));
    }
    sort(a.begin(), a.end(), greater<P<ll, ll> >());
    vll ans(n, 0);
    ll mini=a[0].second;
    REP(i, n) {
        chmin(mini, a[i].second);
        ans[mini] += (i+1) * (a[i].first - a[i+1].first);
    }
    REP(i, n) cout << ans[i] << '\n';
    return 0;
}
