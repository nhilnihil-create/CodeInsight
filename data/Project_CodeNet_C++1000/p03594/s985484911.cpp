#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

void solve() {
    int h, w, d;
    cin >> h >> w >> d;
    if (d % 2) {
        rep(i, h) {
            rep(j, w) {
                cout << ((i + j) % 2 ? "R" : "Y");
            }
            cout << endl;
        }
        return;
    } else {
        d /= 2;
        rep(i, h) {
            rep(j, w) {
                string colors = "RGBY";
                int x = (j + i) / 2;
                int y = (w + i - j) / 2;
                int color = ((x / d) % 2) * 2 + (y / d) % 2;
                cout << colors[color];
            }
            cout << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
