#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    for (int j = 0; j < H+2; j++) {
        cout << '#';
        if (j == 0 || j == H+1) {
            for (int i = 0; i < W; i++) {
                cout << '#';
            }
        }
        else{
            for (int i = 0; i < W; i++) {
                char s;
                cin >> s;
                cout << s; 
            }
        }
        cout << '#' << endl;
    }
}
