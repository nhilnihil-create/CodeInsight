#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T iabs(const T& x) { return max(x, -x); }
// #define abs gabs

int n, ma, mb, dp[401][401], a[40], b[40], c[40];
int main() {
    cin >> n >> ma >> mb;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i <= 400; ++i) {
        for (int j = 0; j <= 400; ++j) {
            if (i != 0 || j != 0) dp[i][j] = 1e8;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 400 - a[i]; j >= 0; --j) {
            for (int k = 400 - b[i]; k >= 0; --k) {
                dp[j + a[i]][k + b[i]] = min(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
            }
        }
    }

    int ans = 1e8;
    for (int k = 1; max(k * ma, k * mb) <= 400; ++k) {
        ans = min(ans, dp[k * ma][k * mb]);
    }
    if (ans >= 1e8) ans = -1;
    cout << ans << endl;
    return 0;
}