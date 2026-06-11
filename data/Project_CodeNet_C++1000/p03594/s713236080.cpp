#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int H, W, d;
    cin >> H >> W >> d;
    if (d%2 == 1) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << (((i+j)%2) ? 'R' : 'B');
            }
            cout << "\n";
        }
        return 0;
    }
    else {
        int inf = d*1000;
        int e = d/2;
        vector<vector<char>> ans(H, vector<char>(W));
        for (int i = -d*2; i < H+d*2; i++) {
            for (int j = -d*2; j < W+d*2; j++) {
                if (i%e != 0 || j%e != 0) continue;
                if ((i/e + j/e)%2 != 0) continue;
                char c;
                if (i%d == 0) {
                    if ((j+inf)%(2*d) == (i+inf)%(2*d)) c = 'R';
                    else c = 'Y';
                }else {
                    if ((j+inf)%(2*d) == (i+inf)%(2*d)) c = 'B';
                    else c = 'G';
                }
                
                for (int k = i-e; k <= i+e; k++) {
                    for (int l = j-e; l <= j+e; l++) {
                        if ((k+l-i-j+inf)%2 != e%2 && abs(k-i)+abs(l-j)<e) {
                            if (k < 0 || k >= H) continue;
                            if (l >= 0 && l <= W-1) ans[k][l] = c;
                            if (l+1 >= 0 && l+1 <= W-1) ans[k][l+1] = c;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << ans[i][j];
            }
            cout << "\n";
        }
        return 0;
    }
    return 0;
}