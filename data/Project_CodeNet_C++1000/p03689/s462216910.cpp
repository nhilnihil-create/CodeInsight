#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if (H%h==0 && W%w==0) {
        cout << "No" << endl;
        return 0;
    }
    else if (H%h != 0) {
        cout << "Yes" << endl;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i % h == h-1) cout << -10000*(h-1)-1;
                else cout << 10000;
                if (j < W-1) cout << " ";
                else cout << endl;
            }
        }
    }
    else if (W%w != 0) {
        cout << "Yes" << endl;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (j % w == w-1) cout << -10000*(w-1)-1;
                else cout << 10000;
                if (j < W-1) cout << " ";
                else cout << endl;
            }
        }
    }
    return 0;
}