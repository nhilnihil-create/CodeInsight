#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << s[0] << s.size() - 2 << s[s.size() - 1] << std::endl;
    return 0;
}
