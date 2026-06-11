#include <iostream>

int main()
{
    unsigned long long x;
    std::cin >> x;

    std::cout << ((x / 11 * 2) + ((x % 11 == 0)?0:((x % 11 > 6)?2:1))) << std::endl;
    return 0;
}