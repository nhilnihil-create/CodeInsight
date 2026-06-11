#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define mod 1000000007

int main() {
    int n; std::cin >> n;

    long long power = 1;
    for(int i = 0;i < n ; i++) {
        power *= i+1;
        power %= mod;
    }

    std::cout << power << std::endl;
}