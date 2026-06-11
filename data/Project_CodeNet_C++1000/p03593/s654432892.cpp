#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    vector<ll> c(26, 0);
    rep(i, H) {
        cin >> a[i];
        rep(j, W) {
            c[a[i][j] - 'a']++;
        }
    }
    ll x4 = 0, x2 = 0, x1 = 0;
    rep(i, 26) {
        if (c[i] % 4 == 0) x4++;
        else if (c[i] % 2 == 0) x2++;
        else x1++;
    }
    if (H % 2 == 0) {
        if (W % 2 == 0) {
            if (x1 == 0 && x2 == 0) cout << "Yes\n";
            else cout << "No\n";
        } else {
            if (x1 == 0 && x2 <= H / 2) cout << "Yes\n";
            else cout << "No\n";
        }
    } else {
        if (W % 2 == 0) {
            if (x1 == 0 && x2 <= W / 2) cout << "Yes\n";
            else cout << "No\n";
        } else {
            if (x1 == 1 && x2 <= (H + W - 2) / 2) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}