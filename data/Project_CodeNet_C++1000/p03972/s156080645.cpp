#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cassert>
#include <cstdint>

using namespace std;

int64_t solve_slow(int w, int h, const vector<int64_t>& p, const vector<int64_t>& q) {
    // consider x * y rectanble
    // first column should be constructed
    int64_t ans = 0;
    for (auto qq : q) {
        ans += qq;
    }
    for (int x = 1; x <= w; ++x) {
        // first row in each column should be constructed
        ans += p[x - 1];
        for (int y = 1; y <= h; ++y) {
            if (p[x - 1] > q[y - 1]) {
                ans += q[y - 1];
            } else {
                ans += p[x - 1];
            }
        }
    }

    return ans;
}

int64_t solve(int w, int h, vector<int64_t>& p, vector<int64_t>& q) {
    // add each q (N + 1) times where N = #{p; p > q}
    // add each p (M + 1) times where N = #{q; p <= q}

    int64_t ans = 0;
    for (auto pp : p) {
        ans += pp;
    }
    for (auto qq : q) {
        ans += qq;
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    int64_t curp = 0, curq = 0, sump = 0, sumq = 0;
    for (curp = 0; curp < p.size(); ++curp) {
        while (curq < q.size() && p[curp] > q[curq]) {
            sumq += q[curq];
            ++curq;
        }
        ans += sumq;
        ans += p[curp] * (q.size() - curq);
    }

    return ans;
}

int main() {
    int w, h;
    cin >> w >> h;

    vector<int64_t> p(w);
    for (auto&& pp : p) {
        cin >> pp;
    }

    vector<int64_t> q(h);
    for (auto&& qq : q) {
        cin >> qq;
    }

    cout << solve(w, h, p, q) << endl;

    return 0;
}