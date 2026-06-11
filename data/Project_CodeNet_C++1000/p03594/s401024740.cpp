#include <iostream>
#include <algorithm>
using namespace std;

int h, w, d;
char color[1024][1024];

int main() {
    cin >> h >> w >> d;

    if (d == 1) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if ((i + j) % 2 == 0) {
                    cout << 'B';
                }
                else {
                    cout << 'R';
                }
            }
            cout << endl;
        }
    }
    else {
        for (int i = 0; i < 1024; i++) {
            for (int j = 0; j < 1024; j++) {
                int x = i + j + 3000;
                int y = i - j + 3000;
                y = y / d % 2; 
                x = x / d % 2; 
                color[i][j] = y * 2 + x; 
            }
        }


        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                switch (color[i][j]) {
                    case 0:
                    cout << 'R';
                    break;
                    case 1:
                    cout << 'G';
                    break;
                    case 2:
                    cout << 'B';
                    break;
                    case 3:
                    cout << 'Y';
                    break;
                }
            }
            cout << endl;
        }
    }
}
