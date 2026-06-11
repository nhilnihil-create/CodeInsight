#include <bits/stdc++.h>

int main()
{
    int64_t N;
    int64_t ans = 1;
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        ans *= i;
        ans %= 1000000007;
    }
    std::cout << ans << std::endl;
}
