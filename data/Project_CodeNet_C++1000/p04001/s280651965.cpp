#include <iostream>

auto Pow(std::uint64_t base, std::size_t i) {
    auto result = std::uint64_t(1);

    while (i > 0) {
        if (i % 2 == 0) {
            base *= base;
            i /= 2;
        } else {
            result *= base;
            i--;
        }
    }

    return result;
}

int main() {
    auto s = std::string();
    std::cin >> s;

    auto sum = std::uint64_t(0);
    for (auto i = std::size_t(0); i < s.size(); ++i) {
        const auto num = static_cast<std::uint64_t>(s[i] - '0');

        const auto exp = s.size() - 1 - i;
        auto pow_2 = Pow(2, i);
        sum += num * Pow(10, exp) * pow_2;

        for (auto j = std::size_t(1); j <= exp; ++j) {
            sum += num * Pow(10, exp - j) * pow_2;
            pow_2 *= 2;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}