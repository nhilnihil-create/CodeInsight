#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr int64_t kMod = 1e9 + 7;
constexpr int64_t kMax = 2e5 + 10;

vector<int64_t> AllFactorials(int64_t limit)
{
    vector<int64_t> fact(limit + 1, 1);
    for (int64_t i = 2; i <= limit; i += 1) {
        fact[i] = (fact[i - 1] * i) % kMod;
    }
    return fact;
}

pair<int64_t, int64_t> Euclid(int64_t a, int64_t b)
{
    if (b == 0) {
        return {1, 0};
    }

    auto p = Euclid(b, a % b);
    return {p.second, p.first - a / b * p.second};
}

int64_t Inverse(int64_t num)
{
    auto inv = Euclid(num, kMod).first;
    while (inv < 0) {
        inv += kMod;
    }
    return inv;
}

vector<int64_t> AllInverseFactorials(int64_t limit)
{
    vector<int64_t> inv_fact(limit + 1, 1);
    for (int64_t i = 2; i <= limit; i += 1) {
        inv_fact[i] = (inv_fact[i - 1] * Inverse(i)) % kMod;
    }
    return inv_fact;
}

int64_t Comb(int64_t n, int64_t k)
{
    static auto fact = AllFactorials(kMax);
    static auto inv_fact = AllInverseFactorials(kMax);

    auto res = (inv_fact[k] * inv_fact[n - k]) % kMod;
    res = (res * fact[n]) % kMod;

    return res;
}

int64_t Ways(int64_t start_x, int64_t start_y, int64_t dest_x, int64_t dest_y)
{
    auto rows = dest_x - start_x + 1;
    auto cols = dest_y - start_y + 1;
    auto len = rows + cols - 2;

    return Comb(len, rows - 1);
}

int main()
{
    int64_t rows, cols;
    cin >> rows >> cols;

    int64_t x, y;
    cin >> x >> y;

    int64_t total = 0;
    for (int64_t i = y + 1; i <= cols; i += 1) {
        int64_t ways = Ways(1, 1, rows - x, i);
        ways = (ways * Ways(rows - x + 1, i, rows, cols)) % kMod;
        total = (total + ways) % kMod;
    }

    cout << total << "\n";
    return 0;
}
