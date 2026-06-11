#include <bits/stdc++.h>
using namespace std;

#define     ll     long long int

int main( )
{
    ll s = 0, n, m, i, j, k;
    cin >> n >> m;
    i = min(n, m / 2);
    s += i;
    n -= i;
    m -= (2 * i);
    s += (m / 4);
    cout << s << '\n';
    return 0;
}
