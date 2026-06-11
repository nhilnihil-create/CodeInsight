#include <iostream>
#include <vector>

int main() {
    int a, b, c; std::cin >> a >> b >> c;
    std::cout << std::min(a+b, std::min(b+c, c+a)) << std::endl;

    return 0;
}