#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int n, k, x, y, ans = 0;
    cin >> n >> k >> x >> y;
    rep(i, n) {
        if (i+1 <= k) ans += x;
        else ans += y;
    }
    cout << ans << endl;
    return 0;
}
