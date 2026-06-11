#include <bits/stdc++.h>
using namespace std;

struct Mod
{
    static const auto P = int(1e9+7);
    long long k;

    Mod(const long long k) : k(k%P) {}
};

Mod operator*(const Mod a, const Mod b) { return a.k * b.k; }
Mod& operator*=(Mod& a, const Mod b) { return a = a * b; }

int main()
{
    int N; cin >> N;

    auto candidates = 0;
    auto result = Mod(1);
    for (auto i = 0; i < N; i++)
    {
        int x; cin >> x;
        if (x < 2*(candidates+1)-1)
        {
            result *= candidates+1;
            candidates--;
        }
        candidates++;
    }
    for (auto i = 1; i <= candidates; i++)
        result *= i;
    cout << result.k << endl;
}
