#include <iostream>
using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    int x_start = 0;
    int x_end = w;
    int y_start = 0;
    int y_end = h;
    for (int i = 0; i < n; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            if (x - x_start >= 0) x_start = x;
        } else if (a == 2) {
            if (x_end - x >= 0) x_end = x;
        } else if (a == 3) {
            if (y - y_start >= 0) y_start = y;
        } else if (a == 4) {
            if (y_end - y >= 0) y_end = y;
        }
    }
    if (x_end - x_start < 0) {
        x_end = x_start;
    }

    if (y_end - y_start < 0) {
        y_end = y_start;
    }
    cout << (x_end - x_start) * (y_end - y_start) << endl;
    return 0;
}
