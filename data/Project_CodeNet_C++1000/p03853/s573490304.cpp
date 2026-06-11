#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        string S;
        for(int i = 0; i < W; i++) {
            char C;
            cin >> C;
            S += C;
            cout << C;
        }
        cout << endl;
        cout << S << endl;
    }
}