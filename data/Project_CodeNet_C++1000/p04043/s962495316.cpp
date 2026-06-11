#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int count_5 = 0;
    int count_7 = 0;
    switch (a) {
        case 5:
            ++count_5;
            break;
        case 7:
            ++count_7;
            break;
        default:
            break;
    }
    switch (b) {
        case 5:
            ++count_5;
            break;
        case 7:
            ++count_7;
            break;
        default:
            break;
    }
    switch (c) {
        case 5:
            ++count_5;
            break;
        case 7:
            ++count_7;
            break;
        default:
            break;
    }

    if (count_5 == 2 && count_7 == 1)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}
