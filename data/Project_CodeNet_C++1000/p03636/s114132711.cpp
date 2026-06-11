#include <array>
#include <iostream>
#include <vector>

int main()
{
    std::string S;
    std::cin >> S;
    int n = S.size();
    std::cout << S.at(0) << n - 2 << S.at(n - 1) << std::endl;
}