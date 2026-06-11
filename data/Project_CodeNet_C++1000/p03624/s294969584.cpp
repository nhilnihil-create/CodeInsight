#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
int main()
{
    std::string S;
    std::cin >> S;
    std::array<int, 26> a;
    for (int i = 0; i < 26; i++) {
        a.at(i) = 0;
    }
    for (int i = 0; i < S.size(); i++) {
        a.at(S.at(i) - 'a')++;
    }
    for (int i = 0; i < 26; i++) {
        if (a.at(i) == 0) {
            std::cout << (char)('a' + i) << std::endl;
            return 0;
        }
    }
    std::cout << "None" << std::endl;
}
