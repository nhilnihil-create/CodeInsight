#include <vector>
#include <iostream>

int main()
{
    static const int MAX = 100001;
    std::vector<long long> fact(MAX), fact_inv(MAX), inv(MAX);
    constexpr long long mod = 1000000007;
    auto factinit = [&fact, &fact_inv, &inv](long long mod)
    {
        fact[0] = fact[1] = 1;
        fact_inv[0] = fact_inv[1] = 1;
        inv[0] = inv[1] = 1;
        for (int i = 2; i < MAX; ++i)
        {
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
        }
    };

    int n, m;
    std::cin >> n >> m;
    if (n + 1 != m && n != m + 1 && n != m)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    factinit(mod);

    long long ans = fact[n] * fact[m];
    if (n == m) ans *= 2;
    ans = (ans + mod) % mod;
    std::cout << ans << std::endl;
    return 0;
}
