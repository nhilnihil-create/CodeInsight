#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <time.h>
#include <random>
#include <string>
#include <cassert>
#include <vector>
#include <ostream>
#include <istream>
#include <stack>
#include <deque>
#include <queue>
#include <functional>
#include <chrono>
#include <stack>

using namespace std;

#define int long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define ld long double

ostream& operator<< (ostream &out, const vector<int> &b) {
    for (auto k : b) out << k << " ";
    return out;
}

istream& operator>> (istream& in, pii& b) {
    in >> b.first >> b.second;
    return in;
}

ostream& operator<< (ostream& out, const pii& b) {
    out << "{" << b.first << ", " << b.second << "}";
    return out;
}

template <typename T1, typename T2> inline bool chkmin(T1 &x, const T2 &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T1, typename T2> inline bool chkmax(T1 &x, const T2 &y) {if (x < y) {x = y; return 1;} return 0;}


#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << (x) << "\n";
    const int INF = 1e18;
    // const int mod = 2600000069;
    // const int p = 10;
#else
    #define dbg(x) 57
    const int INF = 1e18;
    // const int mod = 2600000069;
    // const int p = 179;
#endif

const ld PI = acos(-1);

#define time clock() / (double) CLOCKS_PER_SEC

// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,sse3,sse4")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC target("avx2")  
// #pragma GCC optimize("section-anchors")
// #pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
// #pragma GCC optimize("vpt")
// #pragma GCC optimize("rename-registers")
// #pragma GCC optimize("move-loop-invariants")
// #pragma GCC optimize("unswitch-loops")
// #pragma GCC optimize("function-sections")
// #pragma GCC optimize("data-sections")

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0 && a[i] >= 2) {
            ans += a[i] / 2 - 1;
            a[i] = 2;
        } else if (a[i] % 2 == 1 && a[i] >= 3) {
            ans += a[i] / 2 - 1;
            a[i] = 3;
        }
    }
    vector<vector<int>> dp(n, vector<int>(4, -INF));
    dp[0][a[0]] = 0;
    if (a[0] >= 2) {
        chkmax(dp[0][a[0] - 2], 1);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= a[i - 1]; j++) {
            chkmax(dp[i][a[i]], dp[i - 1][j]);
            if (a[i] >= 1 && j >= 1) {
                chkmax(dp[i][a[i] - 1], dp[i - 1][j] + 1);
            }
            if (a[i] >= 2) {
                chkmax(dp[i][a[i] - 2], dp[i - 1][j] + 1);
            }
            if (a[i] >= 3 && j >= 1) {
                chkmax(dp[i][a[i] - 3], dp[i - 1][j] + 2);
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < 4; i++) {
        chkmax(mx, dp[n - 1][i]);
    }
    cout << ans + mx << "\n";
}
/*

*/