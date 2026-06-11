#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <limits>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
//#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for(auto&& val: a)
        std::cin >> val;

    int ans = 0;
    if(a[0] == 1) {
        ++ans;
        std::swap(a[0], a[1]);
    }
    for(int i = 1; i < a.size() - 1; ++i) {
        if(a[i] == i + 1) {
            ++ans;
            std::swap(a[i], a[i + 1]);
        }
    }
    if(a[N - 1] == N) ++ ans;

    std::cout << ans << std::endl;

    return 0;
}
