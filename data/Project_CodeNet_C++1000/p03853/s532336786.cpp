#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    char im[h+1][w+1];
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> im[i][j];
        }
    }
    for (int i = 1; i <= 2*h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cout << im[(i+1)/2][j];
        }
        cout << endl;
    }
}

int main() {

    solve();
    return 0;
}
