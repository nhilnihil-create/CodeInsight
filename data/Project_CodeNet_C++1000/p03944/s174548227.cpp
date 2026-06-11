#include <iostream>
#include <vector>
using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    int xl, xr, yb, yt;
    xl = 0;
    xr = W;
    yb = 0;
    yt = H;

    for (int i=0; i<N; ++i) {
        int x, y;
        int a;
        cin >> x >> y >> a;

        if (a == 1) {
            if (x > xl) xl = x;
        }
        else if (a == 2) {
            if (x < xr)xr = x;
        }
        else if (a == 3) {
            if (y > yb) yb = y;
        }
        else if (a == 4) {
            if (y < yt) yt = y;
        }
    }

    int area;
    if ((xl >= xr) || (yb >= yt)) {
        area = 0;
    }
    else {
        area = (xr - xl) * (yt - yb);
    }

    cout << area << endl;
}