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
#include <complex>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>
#include <iterator>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;

int main() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    using P = pair<i64, i64>;
    vector<P> l(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        l[i] = { a[i], a[i + 1] };
        if (l[i].first > l[i].second) l[i].second += m;
    }
    sort(begin(l), end(l));
    i64 scr = 0;
    for (int i = 0; i < n - 1; ++i) {
        scr += l[i].second - l[i].first;
    }
    for (int i = 0; i < n - 1; ++i) {
        l.emplace_back(l[i].first + m, l[i].second + m);
    }

    i64 ans = scr, sum_seg = 0, sum_end = 0;
    auto cmp = [](P a, P b) { return a.second > b.second; };
    priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
    for (int x = 0, i = 0; x < 2 * m; ++x) {
        while (!pq.empty() && pq.top().second < x) {
            auto a = pq.top();
            sum_seg -= a.second - a.first;
            sum_end -= a.second;
            pq.pop();
        }
        while (i < l.size() && l[i].first < x) {
            auto a = l[i];
            sum_seg += a.second - a.first;
            sum_end += a.second;
            pq.push(a);
            ++i;
        }
        // cerr << sum_seg << ' ' << sum_end << ' ' << pq.size() << endl;
        i64 res = scr - sum_seg + (sum_end - x * pq.size()) + pq.size();
        ans = min(ans, res);
    }

    cout << ans << endl;
    
    return 0;
}