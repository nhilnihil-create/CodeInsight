#include <bits/stdc++.h>
 
using namespace std;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, N;
    cin >> H >> W >> N;

    vector<int> a(N);

    for(int i = 0; i < N; i++) cin >> a[i];

    vector<vector<int> > c(H, vector<int>(W));

    int y = 0;
    int x = 0;

    for(int i = 0; i < N; i++) {
        while(a[i] > 0) {
            a[i]--;
            c[y][x] = i + 1;
            if(y % 2) {
                if(x == 0) {
                    y++;
                } else {
                    x--;
                }
            } else {
                if(x == W - 1) {
                    y++;
                } else {
                    x++;
                }
            }
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}