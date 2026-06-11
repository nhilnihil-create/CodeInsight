#include <iostream>
using namespace std;

int main() {
    int H, W, d;
    cin >> H >> W >> d;

    char color[2][2] = {{'R', 'G'}, {'B', 'Y'}};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << color[(i + j) / d % 2][(i - j + 10000) / d % 2];
        }
        cout << endl;
    }

    return 0;
}