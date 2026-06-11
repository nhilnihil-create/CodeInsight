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

V< V<int> > calc(string &s) {
    int n = s.size();
    V< V<int> > ret(n + 1, V<int>(26, n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) ret[i][j] = ret[i + 1][j];
        ret[i][s[i] - 'a'] = i;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int n = s.size();
    V< V<int> > nextidx = calc(s);
    // dp[i]: i 文字目を使わずに構築できる最小文字数
    V<int> dp(n + 1, INF);
    V<char> recon(n + 1, 'a');
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            // 次の文字がない時
            if (nextidx[i][j] == n) {
                if (dp[i] != 1) {
                    dp[i] = 1;
                    recon[i] = 'a' + j;
                }
            } else {  // i 以降でまた同じ文字が出てくる時
                if (chmin(dp[i], dp[nextidx[i][j] + 1] + 1)) recon[i] = 'a' + j;
            }
        }
    }
    
    // 復元
    string ans = "";
    int idx = 0;
    while (idx <= n) {
        ans.push_back(recon[idx]);
        idx = nextidx[idx][recon[idx] - 'a'] + 1;
    }
    cout << ans << '\n';
    return 0;
}
