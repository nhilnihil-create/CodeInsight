// Template
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <complex>
#include <cassert>
#define rep(i, x) for (int i = 0; i < (x); ++i)
#define rng(i, x, y) for (int i = (x); i < (y); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
void solve();
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout << fixed << setprecision(10);
    solve();
    return 0;
}


// Main Code
void solve() {
    int h, w;
    cin >> h >> w;
    rep(i, h) rep(j, w) {
        string s;
        cin >> s;
        if (s == "snuke") {
            cout << (char)('A' + j) << i + 1 << "\n";
        }
    }
    return;
}
