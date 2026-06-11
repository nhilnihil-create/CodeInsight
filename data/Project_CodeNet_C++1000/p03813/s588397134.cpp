#include <iostream>

int main()
{
    unsigned int x;
    std::cin >> x;

    // Constraints-Checker
    if (x < 1 || x > 3000) {
        std::cout << "InputError" << std::endl;
        return -1;
    }

    if (x < 1200) std::cout << "ABC" << std::endl;
    else          std::cout << "ARC" << std::endl;

    return 0;
}