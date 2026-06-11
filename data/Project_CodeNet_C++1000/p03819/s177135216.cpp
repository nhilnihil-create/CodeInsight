#include <bits/stdc++.h>
using i64 = long long;

template <class T = long long int>
class Bit {
    private:
    int len;
    T *arr;
    T init;

    public:
    Bit(int l, T initialValue = 0) : len(l), init(initialValue) {
        arr = new T[l+1];
        for (int i = 0; i < l + 1; i++) {
            arr[i] = initialValue;
        }
    }
    ~Bit() {
        delete[] arr;
    }
    void update(int a, T newval) {
        for (int x = a; x <= len; x += x & -x) arr[x] += newval;
    }
    T query(int a) const {
        if (!a) return init;
        T ret = 0;
        for (int x = a; x > 0; x -= x & -x) ret += arr[x];
        return ret;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        v.emplace_back(l, r + 1);
    }

    std::sort(v.begin(), v.end(), [](auto &lhs, auto &rhs) {
        return lhs.second - lhs.first < rhs.second - rhs.first;
    });

    auto it = v.begin();
    Bit<int> bit(m + 2);
    for (int d = 1; d <= m; d++) {
        while (it != v.end() && it->second - it->first <= d) {
            bit.update(it->first, 1);
            bit.update(it->second, -1);
            it++;
        }
        int ret = 0;
        for (int i = d; i <= m; i += d) {
            ret += bit.query(i);
        }
        std::cout << ret + (v.end() - it) << std::endl;
    }

    return 0;
}
