#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int sign(int x) {
    if (x >= 0)
        return 1;
    else
        return -1;
}

int main() {
    int x, y;
    cin >> x >> y;

    int ans = abs(abs(x) - abs(y));
    if (x == 0) {
        if (y < 0)
            ans++;
    } else if (y == 0) {
        if (x > 0)
            ans++;
    } else if (sign(x) == sign(y)) {
        if (x > y)
            ans += 2;
    } else {
        ans++;
    }

    cout << ans << endl;

    return 0;
}