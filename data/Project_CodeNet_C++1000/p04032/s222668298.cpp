#include <iostream>
#include <string>


int main(int argc, char const *argv[]) {
    std::string s;
    std::cin >> s;
    int start = -1;
    int end = -1;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == s[i+1]) {
            start = i + 1;
            end = i + 2;
            break;
        }
        if (i < s.length()-2 && s[i] == s[i+2]) {
            start = i + 1;
            end = i + 3;
            break;
        }
    }
    std::cout << start << " " << end << std::endl;

    return 0;
}
