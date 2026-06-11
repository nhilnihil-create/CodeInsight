#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

int cmb (int n, int k) {
    int res = 1;
    rep (i, 1, k + 1) {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    double v[n];
    rep (i, 0, n) cin >> v[i];
    sort (v, v + n, greater<double>());

    double ave = 0;
    rep (i, 0, a) ave += v[i];
    ave /= a;

    int cnt = 0;
    rep (i, 0, n) if (v[i] == v[a - 1]) cnt++;

    int ans = 0;
    rep (i, a, b + 1) {
        int cnt2 = 0;
        rep (j, 0, i) if (v[a - 1] == v[j]) cnt2++;
        if (v[0] == v[i - 1]) {
            ans += cmb (cnt, cnt2);
        } else if (i == a) {
            ans += cmb (cnt, cnt2);
        }
    }
    cout << fixed << setprecision (15) << ave << "\n" << ans << "\n";
}