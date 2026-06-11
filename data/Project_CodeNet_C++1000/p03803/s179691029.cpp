#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    if (a == 1) a = 14;
    if (b == 1) b = 14;

    if      (a == b) std::cout << "Draw"  << std::endl;
    else if (a >  b) std::cout << "Alice" << std::endl;
    else             std::cout << "Bob"   << std::endl;       

    return 0;
}
