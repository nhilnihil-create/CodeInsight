#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main() {
    ll i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    int cnt = 0;
    if (i % 2 == 1) cnt++;
    if (j % 2 == 1) cnt++;
    if (l % 2 == 1) cnt++;
    if (cnt <= 1) {
        cout << o + 2 * (i / 2) + 2 * (j / 2) + 2 * (l / 2) << endl;
    } else {
        ll mn = min({i, j, l});
        if (mn != 0 && mn % 2 == 0) {
            cout << o + i + j + l - 1 << endl;
            return 0;
        }
        i -= mn;
        j -= mn;
        l -= mn;
        cout << o + mn * 3 + 2 * (i / 2) + 2 * (j / 2) + 2 * (l / 2) << endl;
    }
    return 0;
}