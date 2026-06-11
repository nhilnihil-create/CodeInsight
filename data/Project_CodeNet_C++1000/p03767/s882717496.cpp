#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    long long N; std::cin >> N;
    std::vector<long long> a(3 * N);
    for (auto& r : a)std::cin >> r;
    std::sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < N; ++i)
        ans += a[(3 * N) - 2 - (2 * i)];
    std::cout << ans << std::endl;

    return 0;
}