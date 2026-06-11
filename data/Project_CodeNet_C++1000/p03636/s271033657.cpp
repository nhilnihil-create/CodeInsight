#include <iostream>

int main(int argc, char **argv)
{
    std::string s;
    std::cin >> s;

    int len = s.size();

    std::cout << s.at(0) << (len-2) << s.at(s.size()-1) << std::endl;
}
