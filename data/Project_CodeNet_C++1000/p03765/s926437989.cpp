#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int ps[N], ps2[N], n, q;
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s, n = s.size();
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1];
        if (s[i - 1] == 'A') ps[i] += 1;
        else ps[i] += 2;
    }
    cin >> s, n = s.size();
    for (int i = 1; i <= n; i++) {
        ps2[i] = ps2[i - 1];
        if (s[i - 1] == 'A') ps2[i] += 1;
        else ps2[i] += 2;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, l2, r2; cin >> l >> r >> l2 >> r2;
        cout << ((ps[r] - ps[l - 1]) % 3 == (ps2[r2] - ps2[l2 - 1]) % 3 ? "YES" : "NO") << "\n";
    }

    return 0;
}
