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

int n;
V< P<int, int> > x;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    x.resize(n);
    
    V<int> ans(n * n, -1);
    for (int i = 0; i < n; i++) {
        int tmpx; cin >> tmpx;
        tmpx--;
        x[i] = make_pair(tmpx, i + 1);
        ans[tmpx] = i + 1;
    }

    sort(ALL(x));

    int left = 0, right = n * n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < x[i].second - 1; j++) {
            while (ans[left] != -1) left++;
            if (left > x[i].first) {
                cout << "No\n";
                return 0;
            }
            ans[left] = x[i].second;
        }
    }

    reverse(ALL(x));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - x[i].second; j++) {
            while (ans[right] != -1) right--;
            if (right < x[i].first) {
                cout << "No\n";
                return 0;
            }
            ans[right] = x[i].second;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n * n; i++) cout << ans[i] << (i == n * n - 1 ? '\n' : ' ');
    return 0;
}
