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
#include <numeric>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET{IOSET(){cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main Code
constexpr int maxd = 10;
int n, m, q;
vector<int> v, d, c;
vector<vector<int>> g, dp;

void peint(int ve, int di, int num) {
    if (dp[ve][di] != q) return;
    dp[ve][di] = num;
    if (di) {
        peint(ve, di - 1, num);
        for (int u: g[ve]) peint(u, di - 1, num);
    }
    return;
}

int main() {
    cin >> n >> m;
    g = vector<vector<int>>(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b); g[b].push_back(a);
    }
    cin >> q;
    v = d = c = vector<int>(q);
    rep(i, q) {
        cin >> v[i] >> d[i] >> c[i];
        --v[i];
    }
    
    dp = vector<vector<int>>(n, vector<int>(maxd + 1, q));
    for (int i = q - 1; i >= 0; --i) peint(v[i], d[i], i);
    
    rep(i, n) {
        if (dp[i][0] == q) cout << 0 << "\n";
        else cout << c[dp[i][0]] << "\n";
    }
    return 0;
}
