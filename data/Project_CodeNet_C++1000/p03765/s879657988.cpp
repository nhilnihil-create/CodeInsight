#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(a) (int) (a).size()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);
    vector<int> ss[2], tt[2];
    ss[0].resize(n);
    ss[1].resize(n);
    tt[0].resize(m);
    tt[1].resize(m);
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            ss[0][i] = ss[0][i - 1];
            ss[1][i] = ss[1][i - 1];
        }
        ss[s[i] - 'A'][i]++;
    }
    for (int i = 0; i < m; i++) {
        if (i != 0) {
            tt[0][i] = tt[0][i - 1];
            tt[1][i] = tt[1][i - 1];
        }
        tt[t[i] - 'A'][i]++;
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sa = ss[0][b - 1] - (a - 2 >= 0 ? ss[0][a - 2] : 0);
        int sb = ss[1][b - 1] - (a - 2 >= 0 ? ss[1][a - 2] : 0);
        int ta = tt[0][d - 1] - (c - 2 >= 0 ? tt[0][c - 2] : 0);
        int tb = tt[1][d - 1] - (c - 2 >= 0 ? tt[1][c - 2] : 0);
        if (abs(sa + 2 * sb - (ta + 2 * tb)) % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}