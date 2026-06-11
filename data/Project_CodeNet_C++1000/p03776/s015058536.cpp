#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int cmb (int a, int b) {
    int res = 1;
    rep (i, 0, b) {
        res *= (a - i);
        res /= (i + 1);
    }
    return res;
}

signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    int v[n];
    rep (i, 0, n) cin >> v[i];
    sort (v, v + n, greater<int>());
    double sum = 0;
    int memo = v[a - 1];
    int cnt2 = 0;
    rep (i, 0, a) {
        sum += v[i];
        if (memo == v[i]) cnt2++;
    }
    int cnt = 0;
    rep (i, 0, n) if (memo == v[i]) cnt++;
    int ans = 0;
    if (v[0] != v[a - 1]) {
        ans = cmb (cnt, cnt2);
    } else {
        rep (i, a, min (b + 1, cnt + 1)) { ans += cmb (cnt, i); }
    }
    cout << fixed << setprecision (15) << sum / a << "\n" << ans << "\n";
}