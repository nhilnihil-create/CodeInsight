#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::size_t F(const std::vector<std::size_t>& v, const std::vector<bool>& b)
{
    auto x = std::size_t(0);
    auto t = std::size_t(0);

    t = v[0];
    for (auto i = std::size_t(0); i < b.size(); ++i)
    {
        if (b[i])
        {
            x += t;
            t = v[i + 1];
        }
        else
        {
            t *= 10;
            t += v[i + 1];
        }
    }
    x += t;

    return x;
}

int main()
{
    auto s_in = std::string("");
    std::cin >> s_in;

    auto v = std::vector<std::size_t>();
    for (const auto& s : s_in) v.emplace_back(s - '0');

    auto result = std::size_t(0);

    for (auto i = std::size_t(0); i < static_cast<std::size_t>(std::pow(2, v.size() - 1)); ++i)
    {
        auto separator_flag = std::vector<bool>();
        for (auto n = std::size_t(v.size() - 1); n > 0; --n)
        {
            separator_flag.emplace_back(
                static_cast<bool>((i & static_cast<std::size_t>(std::pow(2, n - 1))) >> (n - 1)));
        }
        result += F(v, separator_flag);
    }

    std::cout << result << std::endl;

    return 0;
}