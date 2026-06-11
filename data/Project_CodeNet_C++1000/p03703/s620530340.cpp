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
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}
#define DEBUG_VLL(vec) REP(i, vec.size()) cerr<<vec[i]<<(i==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

ll merge(vll &b, ll n, ll left, ll mid, ll right) {
    ll cnt = 0;
    ll n1 = mid - left;
    ll n2 = right - mid;
    vll L(n1+1), R(n2+1);
    REP(i, n1) L[i] = b[left+i];
    REP(i, n2) R[i] = b[mid+i];
    L[n1] = R[n2] = HIGHINF;
    ll i = 0, j = 0;
    rep(k, left, right) {
        if (L[i] <= R[j]) {
            b[k] = L[i++];
        } else {
            b[k] = R[j++];
            cnt += n1 - i;
        }
    }
    return cnt;
}

ll merge_sort(vll &b, ll n, ll left, ll right) {
    if (left+1 < right) {
        ll mid = (left + right) / 2;
        ll ans1 = merge_sort(b, n, left, mid);
        ll ans2 = merge_sort(b, n, mid, right);
        ll ans3 = merge(b, n, left, mid, right);
        return ans1 + ans2 + ans3;
    } else return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vll a(n), b(n+1, 0);
    REP(i, n) {
        cin >> a[i];
        b[i+1] = b[i] + a[i] - k;
    }
    cout << n*(n+1)/2 - merge_sort(b, n+1, 0, n+1) << '\n';
    return 0;
}
