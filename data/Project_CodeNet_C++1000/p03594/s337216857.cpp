#include <bits/stdc++.h>

int main() {
    int h, w, d;
    char t[] = { 'R', 'Y', 'G', 'B' };
    std::cin >> h >> w >> d;
    std::vector<std::vector<int>> b(500, std::vector<int>(500));

    if (d % 2) {
        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
                b[i][j] = (i + j) % 2;
            }
        }
    } else {
        for (int i = 0; i < 500; i++) {
            for (int j = 0; j < 500; j++) {
                int p = (i - j + 500 * d) % (d * 500) / d % 2,
                    q = (i + j) / d % 2;
                b[i][j] = (p << 1) + q;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) std::cout << t[b[i][j]];
        std::cout << std::endl;
    }

    return 0;
}