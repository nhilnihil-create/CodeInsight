#include <array>
#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    int l, r;
    for (int a = 0; a < s.size(); a++) {
        if (s.at(a) == 'A') {
            l = a;
            break;
        }
    }
    for (int a = s.size() - 1; a >= 0; a--) {
        if (s.at(a) == 'Z') {
            r = a;
            break;
        }
    }
    std::cout << r - l + 1 << std::endl;
}