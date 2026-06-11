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


int main() {
    long long n, l; std::cin >> n >> l;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + a[i + 1] >= l) {
            std::cout << "Possible" << std::endl;
            for (int j = 1; j <= i; j++) std::cout << j << std::endl;
            for (int j = n - 1; j >= i + 1; j--) std::cout << j << std::endl;
            return 0;
        }
    }
    std::cout << "Impossible" << std::endl;
    return 0;
}
