#include <iostream>

using int64 = long long;

int64 gcd(int64 a, int64 b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int64 lcm(int64 a, int64 b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int N;
    std::cin >> N;
    int64 res = 1;
    for (int i = 0; i < N; i++) {
        int64 T;
        std::cin >> T;
        res = lcm(res, T);
    }

    std::cout << res << std::endl;
    return 0;
}