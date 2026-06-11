#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define l first
#define r second

using namespace std;

const int maxn = 2e5 + 1;

char v[9][9];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    int ans = 0;
    if (x * y < 0 || x
         == 0 && y < 0 ||
        x > 0 && y == 0) {
        ans = abs(x + y) + 1;
    } else {
        if (x > y)
            ans = abs(x - y) + 2;
        else
            ans = abs(x - y);
    }
    cout << ans;
    return 0;
}
