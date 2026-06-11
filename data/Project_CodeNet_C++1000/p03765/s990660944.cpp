#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

int cnt[2][2][100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    string s[2];
    cin >> s[0] >> s[1];
    for (int i = 0; i < 2; i++) {
        s[i] = " " + s[i];
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k < sz(s[i]); k++) {
                cnt[i][j][k] = cnt[i][j][k - 1] + (s[i][k] - 'A' == j);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int foo = cnt[0][1][b] - cnt[0][1][a - 1] - (cnt[0][0][b] - cnt[0][0][a - 1]);
        int baz = cnt[1][1][d] - cnt[1][1][c - 1] - (cnt[1][0][d] - cnt[1][0][c - 1]);
        if ((foo - baz) % 3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}