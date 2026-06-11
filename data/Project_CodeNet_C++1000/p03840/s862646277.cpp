#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

typedef long long ll;
ll a[10], ans;

int main() {
    rep(i, 1, 7) cin >> a[i];
    ans = a[2];
    if (!(a[1] && a[4] && a[5]))
        ans += a[1] / 2 * 2, ans += a[4] / 2 * 2, ans += a[5] / 2 * 2;
    else
        ans += a[1] + a[4] + a[5] - !(a[1] % 2 == a[4] % 2 && a[4] % 2 == a[5] % 2);
    printf("%lld\n", ans);
    return 0;
}
