#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
// #include <bits/stdc++.h>


using namespace std;
typedef long long li;


// Index range: [1, n]
// sum(x) returns the sum over [1, x]
// add(x, v) adds v to the value at x.
template <class T>
struct BIT {
    int n;
    vector<T> bit;

    BIT(int _n): n(_n), bit(_n + 1) {}

    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, T x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

template <class T>
struct RangeAddBIT {
    BIT<T> bit;
    // index: [1, n]
    RangeAddBIT(int n): bit(n + 1) {}

    void range_add(int l, int r, T v) {
        // add v to [l, r]
        if (r < l) {
            return;
        }
        bit.add(l, v);
        bit.add(r + 1, -v);
    }

    T get_at(int i) {
        return bit.sum(i);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    li n, m;
    cin >> n >> m;
    vector<vector<pair<li, li>>> ranges(m + 1);
    for (int i = 0; i < n; ++i) {
        li l, r;
        cin >> l >> r;
        ranges[r - l + 1].emplace_back(l, r);
    }

    RangeAddBIT<li> rab(m);
    li longer = n;
    for (int d = 1; d <= m; ++d) {
        li ans = longer;
        for (int p = d; p <= m; p += d) {
            ans += rab.get_at(p);
        }
        cout << ans << endl;

        for (auto && range: ranges[d]) {
            rab.range_add(range.first, range.second, 1);
            longer--;
        }
    }


    return 0;
}
