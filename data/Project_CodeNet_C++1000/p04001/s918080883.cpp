#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    const auto len = s.length();
    int64_t result{};
    for (uint64_t pattern = 0; pattern < (1ULL << (len - 1)); pattern++) {
        int64_t digit = 1;
        std::bitset<32> bits(pattern);
        for (size_t i = 0; i < len; i++) {
            result += digit * (s[i] - '0');
            digit = (bits[i]) ? 1 : digit * 10;
        }
    }
    std::cout << result << std::endl;
    return 0;
}