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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n); REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[n-1]-a[0] > 1) cout << "No" << '\n';
    else if (a[n-1] == a[0]) {
        if (a[0]==n-1) cout << "Yes" << '\n';
        else if (2*a[0] <= n) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    } else {
        ll ac=1;
        rep(i, 1, n) {
            if (a[i] == a[i-1]) ac++;
            else break;
        }
        if (ac <= a[0] && 2*(a[n-1]-ac)<=n-ac) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
