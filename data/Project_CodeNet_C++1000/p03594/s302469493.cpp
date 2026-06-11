#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, d; cin >> h >> w >> d;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int x = ((i + j) / d % 2 + 2) % 2;
            int y = ((i + w - j) / d % 2 + 2) % 2;
            cout << "RYGB"[x << 1 | y];
        }
        cout << endl;
    }
    return 0;
}