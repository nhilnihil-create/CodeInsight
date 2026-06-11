#include <iostream>
#include <string>
#include<vector>


int main() {
    long long n, t; std::cin >> n >> t;

    std::vector<long long> T(n);
    for(int i = 0; i < n;i ++) {
        std::cin >> T[i];
    }

    long long ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if (std::abs(T[i + 1] - T[i]) < t)
        {
            ans += std::abs(T[i + 1] - T[i]);
        }
        else
        {
            ans += t;
        }
    }

    ans += t;

    std::cout << ans << "\n";

}