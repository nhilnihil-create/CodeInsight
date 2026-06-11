#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if(i%2 == 0) {
            std::cout << s[i];
        }
    }

    std::cout << "\n";
}