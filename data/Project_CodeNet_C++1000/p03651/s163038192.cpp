#include <iostream>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int gcd(int a, int b)
{
    int x = max(a, b),
        y = min(a, b);
    if (x % y)
        gcd(b, a % b);
    else
        return b;
}
int main()
{
    int n, k;
    cin >> n >> k;
    bool ans = false;
    int g = 0, M = 0;
    cin >> g;
    M = g;
    if (g == k)
        ans = true;
    repi(i, n, 1)
    {
        int a;
        cin >> a;
        M = max(M, a);
        if (k == a)
            ans = true;
        g = gcd(g, a);
        if (k % g == 0 & M >= k)
            ans = true;
    }
    if (ans)
        puts("POSSIBLE");
    else
        puts("IMPOSSIBLE");
    return 0;
}