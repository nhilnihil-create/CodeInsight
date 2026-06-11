#include <iostream>
#include <algorithm>
using namespace std;

int h, w, d;
char color[] = {'Y', 'R', 'G', 'B'};

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
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int y = (i - j + 3000) / d;
                int x = (i + j + 3000) / d;
                cout << color[y % 2 * 2 + x % 2]; 
            }
            cout << '\n';
        }
    }
}