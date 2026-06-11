#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, mx;
ll d[105];

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        ll t;
        scanf("%lld", &t);
        d[t]++;
        mx = max(mx, t);
    }
    for(ll i = 0; i <= mx; i++)
    {
        ll t = max(i, mx - i);
        if(d[t] == 0)
        {
            printf("Impossible\n");
            return 0;
        }
        d[t]--;
    }
    for(ll i = 0; i <= (mx + 1) / 2; i++)
    {
        if(d[i] > 0)
        {
            printf("Impossible\n");
            return 0;
        }
    }
    printf("Possible\n");
    return 0;
}
