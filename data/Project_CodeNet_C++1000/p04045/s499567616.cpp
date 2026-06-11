#include <bits/stdc++.h>

void solve(unsigned n, const std::vector<unsigned>& d)
{
    bool t[10] = {};
    for (const unsigned x : d)
        t[x] = true;

    const auto check = [&t](unsigned n) {
        do {
            if (t[n % 10])
                return false;
            n /= 10;
        } while (n != 0);

        return true;
    };

    while (!check(n))
        ++n;

    std::cout << n << '\n';
}

int main()
{
    unsigned n;
    std::cin >> n;

    size_t k;
    std::cin >> k;

    std::vector<unsigned> d(k);
    for (size_t i = 0; i < k; ++i)
        std::cin >> d[i];

    solve(n, d);

    return 0;
}

