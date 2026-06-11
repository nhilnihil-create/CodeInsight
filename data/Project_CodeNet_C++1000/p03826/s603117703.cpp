#include <iostream>

int main()
{
    int a, b;
    int c, d;
    std::cin >> a >> b >> c >> d;

    int area_ab { a * b };
    int area_cd { c * d };

    if (area_ab > area_cd) {
        std::cout << area_ab << std::endl;
    }
    else {
        std::cout << area_cd << std::endl;
    }
    
    return 0;
}