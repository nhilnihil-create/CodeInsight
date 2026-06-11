#include<iostream>

auto CalculateState(const std::string& s, std::uint64_t i) {
    constexpr auto f = [](const auto& c) { return static_cast<std::uint64_t>(c - '0'); };
    auto result = std::uint64_t(0);
    auto target = f(s[0]);

    for (auto j = std::size_t(1); j < s.length(); ++j) {
        const auto flag = ((i >> (j - 1)) & 1) == 1;

        if (flag) {
            result += target;
            target = f(s[j]);
        } else {
            target = target * 10 + f(s[j]);
        }
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