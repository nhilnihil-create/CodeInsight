#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (i % 2 == 0) { std::cout << s[i]; }
    }

    std::cout << std::endl;
    return 0;
}
