#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        puts("Draw");
    }
    else if (a == 1)
    {
        puts("Alice");
    }
    else if (b == 1)
    {
        puts("Bob");
    }
    else if (a > b)
    {
        puts("Alice");
    }
    else if (a < b)
    {
        puts("Bob");
    }
    return 0;
}