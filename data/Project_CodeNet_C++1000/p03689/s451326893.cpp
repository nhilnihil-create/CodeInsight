#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll H, W, h, w;
ll x, y;
ll d[505];

int main()
{
    cin>>H>>W>>h>>w;
    if(H % h == 0 && W % w == 0)
    {
        printf("No\n");
        return 0;
    }
    else if(H % h > 0) x = H, y = h;
    else x = W, y = w;
    printf("Yes\n");
    for(ll i = 0; i < x; i++)
    {
        ll t1 = x % y;
        ll t2 = y - x % y;
        if(i % y < x % y) d[i] = 200000;
        else d[i] = -(200000 * t1) / t2 - 1;
    }
    for(ll i = 0; i < H; i++)
    {
        for(ll j = 0; j < W; j++)
        {
            if(H % h > 0) printf("%lld ", d[i]);
            else printf("%lld ", d[j]);
        }
        puts("");
    }
    return 0;
}
