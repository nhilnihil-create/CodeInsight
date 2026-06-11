#include <array>
#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    for (int a = 0; a < s.size(); a += 2) {
        std::cout << s.at(a);
    }
    std::cout << std::endl;
}