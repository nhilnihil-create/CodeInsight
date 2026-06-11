#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
using namespace std;

inline namespace atcoder {
    template <typename T, size_t Depth>
    struct vector_helper { using type = vector<typename vector_helper<T, Depth - 1>::type>; };
    template <typename T>
    struct vector_helper<T, 0> { using type = T; };
    template <typename T, size_t Depth>
    using vector_t = typename vector_helper<T, Depth>::type;

    template <typename T> using vec = vector_t<T, 1>;
    template <typename T> using vvec = vector_t<T, 2>;
    template <typename T> using vvvec = vector_t<T, 3>;
}

int main() {
    constexpr int64_t mod = 1000000000 + 7;

    int n, m; cin >> n >> m;
    if (1 < abs(n - m)) {
        cout << 0 << endl;
        return 0;
    }

    int64_t ans = 1 + (n == m);
    while (n) {
        ans = (ans * n--) % mod;
    }
    while (m) {
        ans = (ans * m--) % mod;
    }
    cout << ans << endl;
}

