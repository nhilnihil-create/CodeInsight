#include <iostream>

int main() {
    std::string s; std::cin >> s;
    int k; std::cin >> k;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            continue;
        }
        int d = 26 - (s[i] - 'a');
        if (k >= d) {
            s[i] = 'a';
            k-= d;
        }
        if (k < 0) {
            break;
        }
    }
    if (k > 0) {
        k = k % 26;
    }
    s.back() += k;
    if (s.back() > 'z') {
        s.back() -= 'z';
    }

    std::cout << s << std::endl;
    return 0;
}