#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int q, h, s, d;
    cin >> q >> h >> s >> d;

    long n;
    cin >> n;

    long ans = 0;

    int m = min({4 * q, 2 * h, s});
    ans = (n / 2) * min(2 * m, d) + (n % 2) * m;

    cout << ans << endl;
    return 0;
}