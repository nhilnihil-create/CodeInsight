#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct Doubling {
    int sz, n;
    vector<vector<int>> table;
    Doubling(int n, long long ma = 1LL << 62) : sz(0), n(n) {
        while ((1LL << sz) < ma) ++sz;    // 64 - __builtin_clzll(ma)
        table.assign(sz, vector<int>(n, -1));
    }
    void set_next(int i, int x) { table[0][i] = x; }
    void build() {
        for (int k = 0; k < sz - 1; k++) for (int i = 0; i < n; i++) {
            if (~table[k][i]) table[k + 1][i] = table[k][table[k][i]];
        }
    }
    int query(int i, long long t) {
        for (int k = sz - 1; k >= 0; k--) {
            if (t >> k & 1) i = table[k][i];
        }
        return i;
    }
    long long lower_bound(int s, int t) {
        if (s == t) return 0;
        if (s > t) swap(s, t);
        long long ret = 1;
        for (int k = sz - 1; k >= 0; k--) {
            if (table[k][s] < t) ret += 1LL << k, s = table[k][s];
        }
        return ret;
    }
};

int main() {
    int n; cin >> n;
    vector<int> x(n);
    for (int &xi: x) cin >> xi;
    int l; cin >> l;
    Doubling dbl(n);
    int nxt = 0;
    for (int i = 0; i < n; i++) {
        while (nxt + 1 < n && x[nxt + 1] - x[i] <= l) nxt++;
        dbl.set_next(i, nxt);
    }
    dbl.build();
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b; a--, b--;
        cout << dbl.lower_bound(a, b) << endl;
    }
    return 0;
}