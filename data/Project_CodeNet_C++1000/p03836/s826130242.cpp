#include <iostream>
using namespace std;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    auto move = [](size_t n, char c) {
        while (n--) cout << c;
    };

    size_t w = tx - sx, h = ty - sy;

    move(w, 'R');
    move(h, 'U');
    move(w, 'L');
    move(h, 'D');

    move(1, 'D');
    move(w + 1, 'R');
    move(h + 1, 'U');
    move(1, 'L');
    move(1, 'U');
    move(w + 1, 'L');
    move(h + 1, 'D');
    move(1, 'R');
}

