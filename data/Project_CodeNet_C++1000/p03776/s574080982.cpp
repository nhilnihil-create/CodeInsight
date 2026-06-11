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
    map<double, int, greater<double>> mp;
    rep (i, 0, n) {
        cin >> v[i];
        mp[v[i]]++;
    }
    int cnt = 0;
    double sum = 0;
    int ans = 0;
    double ave = 0;
    for (auto p : mp) {
        if (cnt + p.second < a) {
            sum += p.second * p.first;
            cnt += p.second;
        } else if (a <= cnt + p.second) {
            if (cnt == 0) {
                rep (i, a, min (p.second, b) + 1) { ans += cmb (p.second, i); }
                ave = p.first;
            } else {
                int cnt2 = a - cnt;
                ans += cmb (p.second, cnt2);
                ave = (sum + cnt2 * p.first) / a;
            }
            break;
        }
    }
    cout << fixed << setprecision (15) << ave << "\n" << ans << "\n";
}
