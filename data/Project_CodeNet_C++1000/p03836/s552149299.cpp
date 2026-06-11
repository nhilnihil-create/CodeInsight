#include "bits/stdc++.h"

using namespace std;

void Main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int minMoveX = tx - sx;
    int minMoveY = ty - sy;

    string ans;
    for (int i = 0; i < minMoveX; ++i) {
        ans += 'R';
    }
    for (int i = 0; i < minMoveY; ++i) {
        ans += 'U';
    }
    for (int i = 0; i < minMoveX; ++i) {
        ans += 'L';
    }
    for (int i = 0; i < minMoveY; ++i) {
        ans += 'D';
    }

    ans += 'D';
    for (int i = 0; i < minMoveX; ++i) {
        ans += 'R';
    }
    ans += 'R';
    ans += 'U';
    for (int i = 0; i < minMoveY; ++i) {
        ans += 'U';
    }
    ans += 'L';
    ans += 'U';
    for (int i = 0; i < minMoveX; ++i) {
        ans += 'L';
    }
    ans += 'L';
    ans += 'D';
    for (int i = 0; i < minMoveY; ++i) {
        ans += 'D';
    }
    ans += 'R';
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
