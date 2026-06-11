#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int i = 0, s_len = s.length();
    while (i < s_len) {
        if (s[i] == ',') {
            s[i] = ' ';
        }
        i++;
    }

    std::cout << s << std::endl;

    return 0;
}