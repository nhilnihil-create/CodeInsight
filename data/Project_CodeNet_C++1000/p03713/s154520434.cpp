#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll h, w;
ll a, b, c;
ll mn = 4e18;

ll abs2(ll p){return p > 0 ? p : -p;}

int main()
{
    scanf("%lld%lld", &h, &w);
    for(ll i = 0; i <= h; i++)
    {
        a = w * i;
        b = (h - i) * (w / 2);
        c = w * h - a - b;
        mn = min(mn, max(abs2(a - b), max(abs2(b - c), abs2(c - a))));
    }
    if(h % 3 == 0) mn = 0;
    else mn = min(mn, w);
    swap(h, w);
    for(ll i = 0; i <= h; i++)
    {
        a = w * i;
        b = (h - i) * (w / 2);
        c = w * h - a - b;
        mn = min(mn, max(abs2(a - b), max(abs2(b - c), abs2(c - a))));
    }
    if(h % 3 == 0) mn = 0;
    else mn = min(mn, w);
    printf("%lld", mn);
    return 0;
}
