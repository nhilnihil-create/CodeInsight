#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <limits>
using namespace std;
using ull = unsigned long long int;

ull f(ull a, ull b)
{
    auto g = [](ull x) {
        int cnt;
        for (cnt = 0; x != 0; cnt++)
        {
            x = x / 10;
        }
        return cnt;
    };
    return max(g(a), g(b));
}

int main()
{
    ull N;
    cin >> N;
    vector<std::pair<ull, ull>> p;

    for (ull i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            if (i > N / i)
                break;
            p.emplace_back(i, N / i);
        }
    }

    ull m = 11;
    for (const auto &i : p)
    {
        m = min(m, f(i.first, i.second));
    }

    cout << m << endl;
}