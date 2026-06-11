#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950



int main() {
    std::string s; std::cin >> s;
    int x = s.length(), i;
    std::vector<bool> q(26);
    for (i = 0; i < x; i++) q[s[i] - 'a'] = true;
    for (i = 0; i < 26; i++) {
        if (q[i] == false) {
            std::cout << (char)('a' + i) << std::endl;
            return 0;
        }
    }
    std::cout << "None" << std::endl;
}