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

        auto pow_2 = Pow(2, i);
        auto pow_10 = Pow(10, s.size() - 1 - i);

        sum += num * pow_10 * pow_2;

        while (pow_10 > 0) {
            pow_10 /= 10;

            sum += num * pow_10 * pow_2;

            pow_2 *= 2;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}