#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct node {
    double x;
    double y;
};

double dis(double midx, double midy, double x, double y) {
    double r = sqrt((x - midx) * (x - midx) + (y - midy) * (y - midy));
    return r;
}
signed main() {
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        if (a[i] == 0) {
            continue;
        } else {
            if (i > 0) {
                ans += (a[i] + a[i - 1]) / 2;
                a[i] = (a[i] + a[i - 1]) % 2;
            } else {
                ans += a[i] / 2;
                a[i] %= 2;
            }
        }
    }
    cout << ans << "\n";
}