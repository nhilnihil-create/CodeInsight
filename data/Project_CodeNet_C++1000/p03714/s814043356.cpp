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
    i64 n;
    cin >> n;
    vector<i64> a(3 * n);
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
    }

    vector<i64> sum_l(3 * n + 1), sum_r(3 * n + 1);
    priority_queue<i64, vector<i64>, greater<i64>> pq_l;
    priority_queue<i64> pq_r;
    for (int i = 0; i < 2 * n; ++i) {
        sum_l[i + 1] = sum_l[i] + a[i];
        pq_l.push(a[i]);
        if (pq_l.size() > n) {
            sum_l[i + 1] -= pq_l.top();
            pq_l.pop();
        }
    }
    for (int i = 3 * n - 1; i >= n; --i) {
        sum_r[i] = sum_r[i + 1] + a[i];
        pq_r.push(a[i]);
        if (pq_r.size() > n) {
            sum_r[i] -= pq_r.top();
            pq_r.pop();
        }
    }
    // for (i64 x : sum_l) cerr << x << ' ';cerr << endl;
    // for (i64 x : sum_r) cerr << x << ' ';cerr << endl;
    i64 ans = -(1ll << 60);
    for (int i = n; i <= 2 * n; ++i) {
        ans = max(ans, sum_l[i] - sum_r[i]);
    }
    cout << ans << endl;
    return 0;
}