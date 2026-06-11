#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int H, W, N;
    cin >> H >> W >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int c[H][W]{};
    int h = 0;
    int w = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < a[i]; j++) {
            c[h][w] = i + 1;
            if (h % 2 == 0) {
                w++;
                if (w == W) {
                    h++;
                    w = W - 1;
                }
            } else {
                w--;
                if (w == -1) {
                    h++;
                    w = 0;
                }
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j == W - 1) {
                cout << c[i][j] << "\n";
            } else {
                cout << c[i][j] << " ";
            }
            
        }
    }
    
    return 0;
}