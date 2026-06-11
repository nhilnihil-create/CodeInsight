#include <iostream>
#include <string>

int main()
{
    std::string sa, sb, sc;
    std::cin >> sa >> sb >> sc;

    std::string::iterator head[3] = {sa.begin(), sb.begin(), sc.begin()};
    std::string::iterator tail[3] = {sa.end(), sb.end(), sc.end()};
    char turn = *head[0]++;
    while (true)
    {
        if (head[turn - 'a'] != tail[turn - 'a'])
        {
            turn = *head[turn - 'a']++;
        }
        else
        {
            std::cout << static_cast<char>(turn - 'a' + 'A') << std::endl;
            break;
        }
    }
    return 0;
}
