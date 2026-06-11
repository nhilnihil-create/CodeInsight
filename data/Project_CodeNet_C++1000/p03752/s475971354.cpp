#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <limits>
#include <cmath>

using namespace std;

template<class T>
class Input {
public:
    auto operator()() const {
        T v;
        cin >> v;
        return v;
    }
};

template<class L, class R>
class Input<pair<L, R>> {
public:
    auto operator()() const {
        L l;
        R r;
        cin >> l >> r;
        return make_pair(l, r);
    }
};

template<class U>
class Input<vector<U>> {
public:
    auto operator()() const {
        Input<size_t> in{};
        auto n = in();
        return (*this)(n);
    }
    auto operator()(size_t n) const {
        vector<U> v;
        v.reserve(n);
        Input<U> in{};
        for (size_t i = 0; i < n; ++i) {
            auto u = in();
            v.emplace_back(move(u));
        }
        return v;
    }
};

template<class U>
class Input<vector<vector<U>>> {
public:
    auto operator()() const {
        Input<size_t> in{};
        auto n = in();
        auto m = in();
        return (*this)(n, m);
    }
    auto operator()(size_t n, size_t m) const {
        vector<vector<U>> v;
        v.reserve(n);
        Input<vector<U>> in{};
        for (size_t i = 0; i < n; ++i) {
            auto u = in(m);
            v.emplace_back(move(u));
        }
        return v;
    }
};

class InputType
{
public:
    template<class T>
    operator T() const {
        Input<T> i{};
        return i();
    }
};

auto input() {
    return InputType();
}

size_t bitcount(size_t n) {
    size_t c = 0;
    while (n) {
        if (n & 1ull)
            ++c;
        n >>= 1;
    }
    return c;
}

using ll = long long;
using ull = unsigned long long;

int main() {
    size_t n = input();
    size_t k = input();
    vector<size_t> a(n, 0);
    a.reserve(n);
    for (size_t i = 0; i < n; ++i)
        a[i] = input();
    size_t money = numeric_limits<size_t>::max();
    for (size_t i = 0; i < (1ull << (n - 1)); ++i) {
        auto bit = (i << 1ull) | 1ull;
        size_t count = bitcount(bit);
        if (count < k)
            continue;
        size_t prev = a[0];
        size_t m = 0;
        for (size_t j = 1; j < n; ++j) {
            if (bit & (1ull << j)) {
                if (a[j] <= prev) {
                    m += prev - a[j] + 1;
                    ++prev;
                }
            }
            prev = max(prev, a[j]);
        }
        money = min(money, m);
    }
    cout << money << endl;
    return 0;
}
