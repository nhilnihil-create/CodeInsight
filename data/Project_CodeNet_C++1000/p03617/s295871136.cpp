#include <bits/stdc++.h>
using namespace std;

long long llmax(long long a, long long b)
{
    return a > b ? a : b;
}

int main()
{
    int q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    long long ans = (long long)n / 2 * min(q * 8, min(h * 4, min(s * 2, d)));
    n = n - ((n / 2) * 2);
    ans += n * min(q * 4, min(h * 2, s));

    cout << ans << endl;
}
