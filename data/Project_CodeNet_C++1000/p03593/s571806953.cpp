#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    string a;
    vector<int> c(26, 0), d(4, 0);
    rep(i, H) {
        cin >> a;
        rep(j, W) {
            c[a[j] - 'a']++;
        }
    }
    rep(i, 26) {
        d[c[i] % 4]++;
    }
    if (H % 2) {
        if (W % 2) {
            if (d[1] + d[3] == 1 && d[2] + d[3] <= (H + W - 1) / 2) cout << "Yes\n";
            else cout << "No\n";
        } else {
            if (d[1] + d[3] == 0 && d[2] <= W / 2) cout << "Yes\n";
            else cout << "No\n";
        }
    } else {
        if (W % 2) {
            if (d[1] + d[3] == 0 && d[2] <= H / 2) cout << "Yes\n";
            else cout << "No\n";
        } else {
            if (d[0] == 26) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}