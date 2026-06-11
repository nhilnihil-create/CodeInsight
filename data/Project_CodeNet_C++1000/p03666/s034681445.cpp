#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, a, b, c, d;
ll s, e;
ll now;

int main()
{
    scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
    now = b - a;
    s = c * (n - 1);
    e = d * (n - 1);
    if(s <= now && now <= e)
    {
        printf("YES\n");
        return 0;
    }
    for(ll i = 0; i < n - 1; i++)
    {
        s -= c + d;
        e -= c + d;
        if(s <= now && now <= e)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
