#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

#define mod 1000000007


int main() {
    long long n, m; std::cin >> n >> m;

    long long ans;
    if(m < 2*n) {
        ans = m/2;
    } else {
        ans = n + ((m - 2LL * n) / 4LL);
    }


    std::cout << ans << std::endl;
}