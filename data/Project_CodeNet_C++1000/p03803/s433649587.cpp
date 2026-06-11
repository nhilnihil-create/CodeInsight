#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    if      (a == b) std::cout << "Draw"  << std::endl;
    else if (a == 1) std::cout << "Alice" << std::endl;
    else if (b == 1) std::cout << "Bob"   << std::endl;
    else if (a >  b) std::cout << "Alice" << std::endl;
    else             std::cout << "Bob"   << std::endl;       

    return 0;
}