#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x,y;
    cin >> x >> y;
    ll ans;
    if (x * y > 0) {
        if (y >= x) ans = y - x;
        else ans = x - y + 2;
    } else if (x * y < 0) {
        ans = abs(abs(x)-abs(y)) + 1;
    } else {
        if (y > x) ans = y - x;
        else if (y == x) {
            ans = 0;
        } else {
            ans = x - y + 1;
        }
    }
    cout << ans << endl;
    return 0;
}