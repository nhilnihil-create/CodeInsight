#include <iostream>

int main() {
    unsigned long long n, a, b; std::cin >> n >> a >> b;
    if (a > b) {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (n == 1) {
        std::cout << ((a==b)?1:0) << std::endl;
        return 0;
    }

    std::cout << (b * (n-1) + a) - (b + a * (n-1)) + 1 << std::endl;
    return 0;
}