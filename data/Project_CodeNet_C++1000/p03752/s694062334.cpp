#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    int ans = inf;
    rep(bit, 0, 1 << n) {
        // bit=上げるビルの番号
        int sum = 0;
        int mx = a[0], cnt = 1;
        rep(i, 1, n) {
            if (mx < a[i]) {
                mx = a[i];
                cnt++;
            } else if (bit & 1 << i) {
                sum += ++mx - a[i];
                cnt++;
            }
        }
        if (cnt == k) ans = min(ans, sum);
    }
    cout << ans << "\n";
}