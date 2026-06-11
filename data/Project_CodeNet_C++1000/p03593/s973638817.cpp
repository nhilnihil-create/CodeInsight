#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    REP(i, H) cin >> a[i];
    vector<int> cnt(26);
    REP(i, H) {
        REP(j, W) {
            cnt[a[i][j] - 'a']++;
        }
    }
    int g1, g2, g4;
    if (H % 2 == 0 && W % 2 == 0) {
        g1 = g2 = 0;
        g4 = (H / 2) * (W / 2);
    } else if (H % 2 == 1 && W % 2 == 0) {
        g1 = 0;
        g2 = W / 2;
        g4 = (H / 2) * (W / 2);
    } else if (H % 2 == 0 && W % 2 == 1) {
        g1 = 0;
        g2 = H / 2;
        g4 = (H / 2) * (W / 2);
    } else {
        g1 = 1;
        g2 = H / 2 + W / 2;
        g4 = (H / 2) * (W / 2);
    }
    vector<int> c(4);
    REP(i, 26) {
        c[cnt[i] % 4]++;
    }
    if (c[1] + c[3] != g1) cout << "No" << endl;
    else if (c[2] + c[3] > g2) cout << "No" << endl;
    else cout << "Yes" << endl;
}