#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define mod 1000000007


int main() {
    long long n, a, b; std::cin >> n >> a >> b;
    std::vector<long long> x(n);
    for(int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    long long dp[n];
    dp[0] = 0;

    for(int i = 0;i < n - 1; i++) {
        dp[i+1] = std::min(dp[i]+a*(x[i+1]-x[i]),dp[i] + b);
    }

    std::cout << dp[n-1] << std::endl;

}