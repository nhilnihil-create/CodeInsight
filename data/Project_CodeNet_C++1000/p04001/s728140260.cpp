#include <iostream>

auto CalculateState(const std::string& s, std::uint64_t i) {
    auto result = std::uint64_t(0);
    auto target = static_cast<std::uint64_t>(s[0] - '0');

    for (auto j = std::size_t(1); j < s.length(); ++j) {
        if (i % 2 == 0) {
            target = target * 10 + static_cast<std::uint64_t>(s[j] - '0');
        } else {
            result += target;
            target = static_cast<std::uint64_t>(s[j] - '0');
        }

        i /= 2;
    }

    result += target;

    return result;
}

int main() {
    auto s = std::string();
    std::cin >> s;

    auto sum = std::uint64_t(0);

    for (auto i = std::size_t(0); i < (1 << (s.length() - 1)); ++i) {
        sum += CalculateState(s, i);
    }

    std::cout << sum << std::endl;
    return 0;
}