#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        if (a.front() != t.front())
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }

    bool possible = true;
    vector<pair<int, int>> range(n, make_pair(1, 1000000000));
    range.front().first = range.front().second = t.front();
    range.back().first = range.back().second = a.back();
    for (int i = 1; i < n; ++i) {
        if (t[i] != t[i - 1]) {
            range[i].first = range[i].second = t[i];
        } else {
            range[i].second = min(range[i].second, t[i]);
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] != a[i + 1]) {
            if (range[i].first <= a[i] && a[i] <= range[i].second)
                range[i].first = range[i].second = a[i];
            else
                possible = false;
        } else {
            range[i].second = min(range[i].second, a[i]);
        }
    }

    if (!possible) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    constexpr ll mod = 1000000007;
    for (const auto &r : range) {
        ans *= r.second - r.first + 1;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}