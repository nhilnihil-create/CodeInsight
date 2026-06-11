#include <iostream>

int main()
{
    std::string s; std::cin >> s;
    for (int i = 0; i < 12; i++)
    {
        if (i == 4)
        {
            std::cout << " ";
        }
        std::cout << s[i];
    }
    std::cout << std::endl;
    return 0;
}
