#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    ll mi = min({a * 8, b * 4, c * 2, d});
    ll ans = n / 2 * mi;

    if(n%2==1)
        ans += min({a * 4, b * 2, c});
    cout << ans << endl;

    return 0;
}