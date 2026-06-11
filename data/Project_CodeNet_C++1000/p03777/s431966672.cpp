#include <iostream>

int main() {
    char a, b;
    std::cin >> a >> b;

    if (a == 'H') {
        if (b == 'H')
            std::cout << 'H' << '\n';
        else
            std::cout << 'D' << '\n';
    } else {
        if (b == 'H')
            std::cout << 'D' << '\n';
        else
            std::cout << 'H' << '\n';
    }
    return 0;
}
