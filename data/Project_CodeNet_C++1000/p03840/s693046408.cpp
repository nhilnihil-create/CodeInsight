#include <iostream>
#include <algorithm>

int main() {
    long long ai, ao, at, aj, al, as, az, ret, ret2 = 0;
    std::cin >> ai >> ao >> at >> aj >> al >> as >> az;

    ret = ai / 2 * 2 + aj / 2 * 2 + al / 2 * 2 + ao;
    if (ai > 0 && aj > 0 && al > 0) ret2 = 3 + (ai - 1) / 2 * 2 + (aj - 1) / 2 * 2 + (al - 1) / 2 * 2 + ao;
    std::cout << std::max(ret, ret2) << std::endl;

    return 0;
}