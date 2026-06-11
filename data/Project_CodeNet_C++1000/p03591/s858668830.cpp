#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <sstream>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    std::cin >> str;
    char y = str[0];
    char a = str[1];
    char k = str[2];
    char i = str[3];
    if (y == 'Y' && a == 'A' && k == 'K' && i == 'I') {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << '\n';
    }
    return 0;
}