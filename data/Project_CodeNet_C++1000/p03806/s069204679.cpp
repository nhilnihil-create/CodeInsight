#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

template <typename T> bool chmin(T &a, const T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T> bool chmax(T &a, const T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    const int mx = 410;
    
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    REP(i, n) cin >> a[i] >> b[i] >> c[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(mx * mx, 1000000000));
    dp[0][0] = 0;
    REP(i, n) REP(j, mx * mx) {
        int aa = j / mx, bb = j % mx;
        chmin(dp[i + 1][j], dp[i][j]);
        if (aa + a[i] < mx && bb + b[i] < mx) chmin(dp[i + 1][(aa + a[i]) * mx + (bb + b[i])], dp[i][j] + c[i]);
    }
    
    int ans = 1000000000;
    int aa = ma, bb = mb;
    while (aa < mx && bb < mx) {
        chmin(ans, dp[n][aa * mx + bb]);
        aa += ma; bb += mb;
    }
    
    if (ans == 1000000000) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}
