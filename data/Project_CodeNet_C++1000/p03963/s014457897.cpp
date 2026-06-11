#include <bits/stdc++.h>

int main()
{
    int64_t N, K;
    int64_t ans = 0;
    std::cin >> N >> K;
    ans = K * std::pow(K - 1, N - 1);
    std::cout << ans << std::endl;
}