#if !defined(__clang__) && defined(__GNUC__)
#include <bits/stdc++.h>
#else
#include <cstdlib>
#include <climits>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <complex>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#endif //  !defined(__clang__) && defined(__GNUG__)
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/math/common_factor_rt.hpp>

constexpr int64_t DIV1097 = 1000000007LL;

using namespace std;

/** 二項係数計算
    (1 ≦ k ≦ n ≦ 107 程度)
*/
class Combination {
public:
    Combination(int64_t max, int64_t mod) : mod_(mod) {
        fac_.resize(max+1);
        inv_.resize(max+1);
        finv_.resize(max+1);

        fac_[0] = fac_[1] = 1;
        finv_[0] = finv_[1] = 1;
        inv_[1] = 1;
        for (int64_t i = 2; i <= max; i++){
            fac_[i] = fac_[i - 1] * i % mod;
            inv_[i] = mod - inv_[mod%i] * (mod / i) % mod;
            finv_[i] = finv_[i - 1] * inv_[i] % mod;
        }
    }

    int64_t get(int64_t n, int64_t k) const {
        if (n < k) {
            return 0;
        }
        if (n < 0 || k < 0) {
            return 0;
        }
        return fac_[n] * (finv_[k] * finv_[n - k] % mod_) % mod_;
    }

    std::vector<int64_t> fac_;
    std::vector<int64_t> finv_;
    std::vector<int64_t> inv_;

    int64_t mod_;
};


int main()
{
    int64_t H, W, A, B;
    std::cin >> H >> W >> A >> B;

    Combination C(100000*2, DIV1097);

    int64_t ans = 0;
    for (int64_t x = B; x <= W-1; ++x) {
        /*
          下に H-A-1 回, 右にx回移動と、
          下に A-1回, 右にW-1-x回移動の組み合わせ
        */
        ans += C.get(H-A-1+x, x) * C.get(A-1+W-1-x, A-1);
        ans %= DIV1097;
    }

    std::cout << ans << std::endl;

    return 0;
}
