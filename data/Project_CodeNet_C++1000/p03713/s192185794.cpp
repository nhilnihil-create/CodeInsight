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

int main() {
    i64 h, w;
    cin >> h >> w;
    i64 ans = 1e9;
    for (int k = 0; k < 2; ++k) {
        for (int i = 1; i < h; ++i) {
            i64 a = i * w;
            i64 g = h - i;
            {
                i64 b = g / 2 * w, c = (g - g / 2) * w;
                if (b != 0 && c != 0) {
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
            }
            {
                i64 b = w / 2 * g, c = (w - w / 2) * g;
                if (b != 0 && c != 0) {
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        swap(h, w);
    }
    cout << ans << endl;
    return 0;
}