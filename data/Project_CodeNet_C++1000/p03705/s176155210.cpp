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
    int n, a, b;
    cin >> n >> a >> b;
    int mx = a + b * (n - 1);
    int mn = a * (n - 1) + b;
    int ans = mx - mn + 1;
    if (ans < 0) ans = 0;
    cout << ans << "\n";
}