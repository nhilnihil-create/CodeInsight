#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using i64 = long long;

template <class T = long long int>
class Bit {
    private:
    unsigned len;
    T init;
    std::vector<T> arr;

    public:
    Bit(unsigned length, T initialValue = 0): len(length), init(initialValue), arr(len + 1, init) {}
    void update(unsigned a, T newval) {
        for (unsigned x = a; x <= len; x += x & -x) arr[x] += newval;
    }
    T query(unsigned a) const {
        T ret = init;
        for (unsigned x = a; x > 0; x -= x & -x) ret += arr[x];
        return ret;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<int, int, int>> evs;

    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        ++r;
        evs.emplace_back(r - l, l, r);
    }

    std::sort(evs.begin(), evs.end());

    Bit<int> bit(m + 2);
    auto it = evs.cbegin();
    for (int i = 1; i <= m; i++) {
        int ret = evs.end() - it;
        for (int j = i; j <= m; j += i) {
            ret += bit.query(j);
        }
        while (it != evs.end() && std::get<0>(*it) == i) {
            bit.update(std::get<1>(*it), 1);
            bit.update(std::get<2>(*it), -1);
            it++;
        }
        std::cout << ret << '\n';
    }

    return 0;
}
