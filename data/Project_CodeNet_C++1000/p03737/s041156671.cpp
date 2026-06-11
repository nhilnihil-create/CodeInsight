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
    string a[3];
    rep(i, 0, 3) cin >> a[i];
    string ans = "";
    rep(i, 0, 3) ans += (a[i][0] - 'a' + 'A');
    cout << ans << "\n";
}