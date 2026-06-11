#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Mod
{
    static const auto P = int(1e9+7);
    ll k;

    Mod() = default;
    Mod(const ll k) : k(k%P >= 0 ? k%P : k%P + P) {}
};

Mod operator+(const Mod a, const Mod b) { return a.k + b.k; }
Mod operator-(const Mod a, const Mod b) { return a.k - b.k; }
Mod& operator+=(Mod& a, const Mod b) { return a = a+b; }

int main()
{
    ll n; cin >> n;

    if (n == 1) cout << 1 << endl;
    else if (n == 2) cout << 4 << endl;
    else
    {
        auto last3 = array<Mod, 3>{n*n, n, 1};
        auto sum = Mod(0);
        for (auto k = 3; k <= n; k++)
        {
            sum += last3[2] - 1;
            const auto x = last3[0] + sum + n*(n-1);

            last3[2] = last3[1];
            last3[1] = last3[0];
            last3[0] = x;
        }
        cout << last3[0].k << endl;
    }
}
