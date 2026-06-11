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
    double q, h, s, d;
    int n;
    cin >> q >> h >> s >> d >> n;
    int mn = min({q * 4, h * 2, s});
    int mn2 = min({q * 8, h * 4, s * 2, d});
    int ans = n / 2 * mn2 + n % 2 * mn;
    cout << ans << "\n";
}