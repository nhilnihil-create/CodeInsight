#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int side = 0, row = 0, col = 0;
    vector< vector<int> > c(h, vector<int>(w, 0));
    rep(t, 0, n) {
        int x;
        cin >> x;
        for (int i = 0; i < x; ++i) {
            c[row][col] = t + 1;
            if (side == 0) ++col;
            else --col;
            if (col == w) row++, col = w - 1, side ^= 1;
            else if (col == -1) ++row, col = 0, side ^= 1; 
        }
    }
    for (auto &vec : c) {
        for (auto v : vec) cout << v << ' ';
        cout << '\n';
    }
}