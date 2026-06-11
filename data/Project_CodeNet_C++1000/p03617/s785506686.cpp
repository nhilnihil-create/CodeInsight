#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    s = min({4 * q, 2 * h, s});

    ll ans = 0;
    if (s * 2 > d)
        ans = n / 2 * d + (n % 2) * s;
    else
        ans = s * n;

    cout << ans << endl;
    return 0;
}
