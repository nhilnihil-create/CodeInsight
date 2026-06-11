/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c, d, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d >> n;
    b = min(b, 2 * a);
    c = min(c, 2 * b);
    d = min(d, 2 * c);
    cout << n / 2 * d + n % 2 * c << "\n";
    return 0;
}
