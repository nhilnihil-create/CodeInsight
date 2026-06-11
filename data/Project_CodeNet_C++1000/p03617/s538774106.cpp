#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    ll ans = n / 2 * min({8 * q, 4 * h, 2 * s, d}) +
             (n % 2) * min({4 * q, 2 * h, s});

    cout << ans << endl;
    return 0;
}
