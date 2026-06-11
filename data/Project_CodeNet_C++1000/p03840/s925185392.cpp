#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll a, b, c, d, e;
bool v;
ll ans;

int main()
{
    scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e);
    ans = a / 2 * 2 + d / 2 * 2 + e / 2 * 2;
    if(d > 0 && e > 0 && a > 0)
    {
        a--, d--, e--;
        ans = max(ans, a / 2 * 2 + d / 2 * 2 + e / 2 * 2 + 3);
    }
    printf("%lld\n", ans + b);
    return 0;
}
