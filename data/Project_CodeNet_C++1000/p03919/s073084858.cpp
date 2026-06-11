#include <iostream>
#include <cstdio>
#include <string>

int main() {
    int H, W;
    std::cin >> H >> W;
    for (int y = 0; y < H; ++y)
    for (int x = 0; x < W; ++x) {
        std::string cell;
        std::cin >> cell;
        if ("snuke" == cell) {
            std::printf("%c%d\n", 'A'+x, 1+y);
        }
    }

    return 0;
}
