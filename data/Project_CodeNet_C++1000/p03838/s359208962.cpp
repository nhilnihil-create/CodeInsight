#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll x, y;
    cin >> x >> y;
    ll ans = 1001001001001001001;
    if (y - x >= 0)
        ans = min(ans, y - x);
    if (y - (-x) >= 0)
        ans = min(ans, y - (-x) + 1);
    if (-y - x >= 0)
        ans = min(ans, -y - x + 1);
    if (-y - (-x) >= 0)
        ans = min(ans, -y - (-x) + 2);
    cout << ans << '\n';
}