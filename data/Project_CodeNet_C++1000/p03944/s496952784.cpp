#include <bits/stdc++.h>
using namespace std;
struct point {
    int x;
    int y;
    int a;
};

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y >> points[i].a;
    }
    vector<vector<bool>> field(W + 1, vector<bool>(H + 1, false));

    for (int i = 0; i < N; i++) {
        if (points[i].a == 1) {
            for (int w = 1; w < points[i].x + 1; w++) {
                for (int h = 1; h < H + 1; h++) {
                    field[w][h] = true;
                }
            }
        } else if (points[i].a == 2) {
            for (int w = points[i].x + 1; w < W + 1; w++) {
                for (int h = 1; h < H + 1; h++) {
                    field[w][h] = true;
                }
            }
        } else if (points[i].a == 3) {
            for (int w = 1; w < W + 1; w++) {
                for (int h = 1; h < points[i].y + 1; h++) {
                    field[w][h] = true;
                }
            }
        } else {
            for (int w = 1; w < W + 1; w++) {
                for (int h = points[i].y + 1; h < H + 1; h++) {
                    field[w][h] = true;
                }
            }
        }
    }
    int output = 0;
    for (int w = 1; w < W + 1; w++) {
        for (int h = 1; h < H + 1; h++) {
            if (!field[w][h]) {
                //  cout << w << " " << h << endl;
                output++;
            }
        }
    }
    cout << output << endl;

    return 0;
}
