#include <iostream>
#include <vector>

int main() {
    long long n, par = 0;
    constexpr auto mod = 1000000007;
    std::cin >> n;
    std::vector<long long> v(n + 1);

    v[0] = 1;
    v[1] = n;
    v[2] = n * n;
    for (auto i = 3ll; i <= n; i++) {
        par = (par + v[i - 3]) % mod;
        v[i] = ((n - 1) * (n - 1) + v[i - 1] + n - i + 1 + par) % mod;
    }
    std::cout << v[n] << std::endl;

    return 0;
}