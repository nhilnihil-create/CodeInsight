#include <iostream>

#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    int i;
    for (i = 0; i < s.size() - 2; i++) {
        if (s[i] == s[i + 1] || s[i] == s[i + 2]) {
            break;
        }
    }

    if (s[s.size() - 1] == s[s.size() - 2]) i = s.size() - 3;
    

    if (i == s.size() - 2) std::cout << -1 << " " << -1;
    else if(s[0] == s[1]) std::cout << 1 << " " << 2;
    else std::cout << i  + 1<< " " << i + 3;

    return 0;
}
