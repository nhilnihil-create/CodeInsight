#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
    int H, W;
    cin >> H >> W;
    
    char C[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> C[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << C[i][j];
        }
        cout << endl;
        for (int j = 0; j < W; j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
    
    return 0;
}