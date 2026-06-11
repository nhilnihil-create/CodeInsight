#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
using i64 = int64_t;
template<class T, class F = std::plus<T>>
struct Fenwick {
    int n;
    vector<T> c;
    F f;
    T init;
    Fenwick(int n, F f = plus<T>(), T init = T())
        : n(n), c(n + 1, init), f(f), init(init) {}
    
    T sum(int i) const {
        T x = init;
        while (i > 0) {
            x = f(x, c[i]);
            i -= i & -i;
        }
        return x;
    }
    void add(int i, T x) {
        while (i <= n) {
            c[i] = f(c[i], x);
            i += i & -i;
        }
    }
};
i64 n, m;
vector<vector<pair<int, int>>> ss;
int main() {
    cin >> n >> m;
    ss.resize(m + 1);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ss[r - l + 1].emplace_back(l, r);
    }
    int rest = n;
    Fenwick<int> fen(m + 1);
    for (int d = 1; d <= m; ++d) {
        for (auto p : ss[d]) {
            int l, r;
            tie(l, r) = p;
            fen.add(l, 1);
            fen.add(r + 1, -1);
        }
        rest -= ss[d].size();
        int ans = rest;
        for (int i = 0; i <= m; i += d) {
            ans += fen.sum(i);
        }
        cout << ans << endl;
    }
    
    return 0;
}