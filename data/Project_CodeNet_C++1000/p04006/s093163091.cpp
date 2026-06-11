#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


#line 1 "lib/segment_tree.hpp"



#include <vector>
#include <algorithm>
#include <functional>

template<typename Monoid>
class SegmentTree {
public:
    using Operator = std::function<Monoid(Monoid, Monoid)>;

    SegmentTree(int n, const Operator &op, const Monoid init)
        : op(op), init(init) {

        num = 1;
        while (num < n) num *= 2;
        dat.resize(2 * num, init);
    }

    SegmentTree(const std::vector<Monoid> &m,
        const Operator &op, const Monoid init)
        : SegmentTree(m.size(), op, init) {

        int n = m.size();
        for (int i = 0; i < n; i++) {
            dat[num - 1 + i] = m[i];
        }
        for (int i = num - 2; i >= 0; i--) {
            dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

    // Update the k-th value (0-indexed) to a.
    void update(int k, Monoid a) {
        k += num - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    // Get the value of the range [a, b).
    // k: The index of the node.
    // [left, right): The range corresponds to the k-th node.
    // Call like getval(a, b).
    Monoid getval(int a, int b, int k = 0, int left = 0, int right = -1) {
        if (right < 0) right = num;
        if (right <= a || b <= left) return init;
        if (a <= left && right <= b) return dat[k];
        Monoid vleft = getval(
            a, b, 2 * k + 1, left, left + (right - left) / 2);
        Monoid vright = getval(
            a, b, 2 * k + 2, left + (right - left) / 2, right);
        return op(vleft, vright);
    }

private:
    int num;
    std::vector<Monoid> dat;
    const Operator op;
    const Monoid init;
};


int main() {
    int n; long long x; std::cin >> n >> x;
    std::vector<long long> a(2*n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) a[n + i] = a[i];
    SegmentTree<long long>
        seg(a, [](auto a, auto b) {return std::min(a, b); }, 1e18);
    long long ans = 1e18;
    for (long long i = 0; i < n; i++) {
        long long s = i*x;
        for (int j = n; j < 2 * n; j++) {
            s += seg.getval(j - i, j + 1);
        }
        ans = std::min(ans, s);
    }
    std::cout << ans << std::endl;
    return 0;
}
