#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <iomanip>

using int64 = long long;

class Combination {
private:
    constexpr static int64 DEFAULT = -1;
    std::vector<std::vector<int64>> c;
public:
    Combination(int max)
    {
        c.assign(max, std::vector<int64>(max, DEFAULT));
    }

    // calc nCr
    int64 calc(int n, int r)
    {
        if (n < r)
            return 0LL;

        if (n == r || r == 0)
            return 1LL;

        if (c[n][r] != DEFAULT)
            return c[n][r];

        return c[n][r] = calc(n - 1, r - 1) + calc(n - 1, r);
    }
};

int main()
{
    int N, A, B;
    std::cin >> N >> A >> B;
    std::vector<int64> v(N);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    std::sort(v.rbegin(), v.rend());
    int64 max_sum = std::accumulate(v.begin(), std::next(v.begin(), A), 0LL);
    std::cout << std::fixed << std::setprecision(6)
              << (double)max_sum / A << std::endl;

    Combination comb(51);
    int min_value_count_all = 0;
    for (int i = 0; i < N; i++)
        if (v[i] == v[A - 1])
            min_value_count_all++;

    int64 pattern = 0;
    if (v[0] == v[A - 1]) {
        for (int i = A; i <= B; i++)
            pattern += comb.calc(min_value_count_all, i);
    }
    else {
        int min_value_count = 0;
        for (int i = 0; i < A; i++)
            if (v[i] == v[A - 1])
                min_value_count++;

        pattern = comb.calc(min_value_count_all, min_value_count);
    }
    std::cout << pattern << std::endl;

    return 0;
}
