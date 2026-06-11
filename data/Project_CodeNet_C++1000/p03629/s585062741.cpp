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
    string s; cin >> s;
    
    vll numk(s.size() + 2, 0); numk[s.size() + 1]++;
    vvll chidx(26);  // 各文字の index
    REP(i, 26) chidx[i].push_back(0);
    REP(i, s.size()) chidx[s[i] - 'a'].push_back(i + 1);
    REP(i, 26) chidx[i].push_back(s.size() + 1);

    set<char> chs;
    for (ll i = s.size() - 1; i >= 0; i--) {
        chs.insert(s[i]);
        if (chs.size() == 26) {
            numk[i + 1]++;
            chs.clear();
        }
    }
    REP(i, s.size() + 1) numk[i + 1] += numk[i];

    string t = "";
    ll now = 0;
    REP(i, numk[s.size() + 1]) {
        REP(j, 26) {
            ll idx = upper_bound(ALL(chidx[j]), now) - chidx[j].begin();
            if (numk[chidx[j][idx]] == numk[now] + 1) {
                t.push_back('a' + j);
                now = chidx[j][idx];
                break;
            }
        }
    }
    cout << t << '\n';
    return 0;
}
