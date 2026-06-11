#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

signed main() {
    int n;
    cin >> n;
    int a[3 * n];
    rep (i, 0, 3 * n) cin >> a[i];
    sort (a, a + 3 * n, greater<int>());
    int ans = 0;
    for (int i = 1; i < 2 * n; i += 2) ans += a[i];
    cout << ans << "\n";
}