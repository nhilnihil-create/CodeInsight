#include <bits/stdc++.h>
#define show(x) std::cerr << #x << " = " << (x) << std::endl
using ll = long long;
using ld = long double;
constexpr ll MOD = 1000000007LL;
template <typename T>
constexpr T INF() { return std::numeric_limits<T>::max() / 16; }
std::mt19937 mt{std::random_device{}()};
int main()
{
    ll X, Y;
    std::cin >> X >> Y;
    std::cout << (std::abs(X - Y) <= 1 ? "Brown" : "Alice") << std::endl;
    return 0;
}
