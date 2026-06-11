#include <iostream>
int main() {
    long long n, a, b;
    std::cin >> n >> a >> b;
    if (n == 1 || a > b)
        std::cout << (a == b ? 1 : 0) << '\n';
    else
        std::cout << b * (n - 2) + a * (2 - n) + 1 << '\n';
}