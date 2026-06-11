#include <iostream>

using namespace std;

constexpr int N = 1000001, mod = 1000000007;

int64_t da[N], ans = 1, cv = 1;

int64_t prod(int64_t a, int64_t b) {return a * b % mod;}
int64_t mul(int64_t &a, int64_t b) {return (a *= b) %= mod;}
int64_t add(int64_t &a, int64_t b) {return (a += b) %= mod;}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        add(da[i + 3], add(cv, add(da[i], da[i - 1]))),
        add(ans, prod(cv, prod(n - 1, i == n? 1: n)));
    cout << ans << '\n';
    return 0;
}
