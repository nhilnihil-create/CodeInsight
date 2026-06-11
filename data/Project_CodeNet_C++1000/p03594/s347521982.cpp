#include <bits/stdc++.h>

constexpr char letters[] = { 'R', 'G', 'B', 'Y' };

int main() {

    int H, W, D;
    std::cin >> H >> W >> D;

    int origin_x = 0, origin_y = H - 1;
    std::vector<std::vector<int>> grid(H + W - 1, std::vector<int>(H + W - 1));
    std::function<void(int&, int&)> rotate45 = [&] (int& x, int& y) {
        int u = origin_x + x + y;
        int v = origin_y - x + y; 
        x = u;
        y = v;
    };

    for (int i = 0; i < H + W - 1; ++i) {
        for (int j = 0; j < H + W - 1; ++j) {
            grid[i][j] = 1 * (i / D % 2) + 2 * (j / D % 2);
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int x = i, y = j;
            rotate45(x, y);
            std::cout << letters[grid[x][y]];
        }
        std::cout << '\n';
    }

}
