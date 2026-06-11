/*
    飲んだ魔剤で家が建つ。
    created at: 2020-05-01 23:05:44
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF 1000000000

int main()
{
    long h, w;
    cin >> h >> w;

    long p = w * ( ceil((float)h/3) - h/3 );
    long q = h * ( ceil((float)w/3) - w/3 );

    long ans = min(p, q);

    for (long x = 1; x <= h-1; x++) {
        long y = w/2;
        long a, b, c;
        a = x * w;
        b = (h-x) * y;
        c = (h-x) * (w-y);

        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);

        if (ans > c-a) ans = c-a;
    }

    for (long y = 1; y <= w-1; y++) {
        long x = h/2;
        long a, b, c;
        a = h * y;
        b = x * (w-y);
        c = (h-x) * (w-y);

        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);

        if (ans > c-a) ans = c-a;
    }

    cout << ans << endl;

    return 0;
}
