#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

ll div_ceil(ll a, ll b)
{
    ll s = a / b;
    if (a % b != 0) s++;
    return s;
}

int main( )
{
    ll a, b, x, y, n, p, q, g;
    cin >> n;
    x = 1;
    y = 1;
    while (n--) {
        cin >> a >> b;
        g = max(div_ceil(x, a), div_ceil(y, b));
        x = g * a;
        y = g * b;
    }
    cout << (x + y) << '\n';
    return 0;
}
