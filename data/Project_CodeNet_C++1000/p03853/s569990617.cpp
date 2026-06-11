#include<iostream>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    string C[H];
    for (int i = 0; i < H; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0 ; j < W; j++) {
            cout << C[i][j];
        }
        cout << endl;
        for (int j = 0 ; j < W; j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
}
