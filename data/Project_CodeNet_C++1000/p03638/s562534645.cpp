#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int H,W,N; cin >> H >> W >> N;
    vector<vector<int>> C(W, vector<int>(H));
    bool right = true;
    int x = 0, y = 0;
    rep(i,N) {
        int a; cin >> a;
        rep(j, a) {
            C[x][y] = i + 1;
            if (right) {
                if (x + 1 == W) {
                    right = false;
                    y++;
                } else {
                    x++;
                }
            } else {
                if (x == 0) {
                    right = true;
                    y++;
                } else {
                    x--;
                }
            }
        }
    }

    rep (y, H) {
        rep (x, W) {
            cout << C[x][y] << " ";
        }
        cout << endl;
    }
}
