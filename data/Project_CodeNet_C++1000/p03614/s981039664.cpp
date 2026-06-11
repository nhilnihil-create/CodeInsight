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
    int N;
    std::cin >> N;
    std::vector<int> p(N);
    for (int i = 0; i < N; i++) { std::cin >> p[i]; }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (p[i] == i + 1) { std::swap(p[i], p[i + 1]), ans++; }
    }
    std::cout << ans << std::endl;
    return 0;
}
