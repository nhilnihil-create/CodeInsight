#include <iostream>

int main()
{
    unsigned int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    unsigned int area_ab { a * b }, area_cd { c * d};

    if (area_ab > area_cd) std::cout << area_ab << std::endl;
    else                   std::cout << area_cd << std::endl;

    // Another way (require <algorithm> header):
    // std::max(area_ab, area_cd);

    return 0;
}