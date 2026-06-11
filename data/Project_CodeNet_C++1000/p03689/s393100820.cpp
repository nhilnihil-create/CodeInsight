#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    
    if (H % h == 0 && W % w == 0) {
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl;
    
    if (H % h != 0) {
        int a = H, b = -H * (h-1) - 1;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i % h == h-1) {
                    cout << b << " ";
                } else {
                    cout << a << " ";
                }
            }
            cout << endl;
        }
    } else {
        int a = W, b = -W * (w-1) - 1;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (j % w == w-1) {
                    cout << b << " ";
                } else {
                    cout << a << " ";
                }
            }
            cout << endl;
        }
    }
            
    
    
    return 0;
}
