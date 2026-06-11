#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a + b < 24)
        std::cout << (a + b) << '\n';
    else
        std::cout << (a + b) - 24 << '\n';

    return 0;
}
