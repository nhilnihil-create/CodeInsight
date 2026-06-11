#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
int main()
{
    int W, H, N;
    std::cin >> W >> H >> N;
    std::vector<std::vector<int>> area(100, std::vector<int>(100, 0));
    int x, y, a;
    for (int i = 0; i < N; i++) {
        std::cin >> x >> y >> a;
        if (a == 1) {
            for (int h = 0; h < H; h++) {
                for (int j = 0; j < x; j++) {
                    area.at(h).at(j) = 1;
                }
            }
        }
        if (a == 2) {
            for (int h = 0; h < H; h++) {
                for (int j = x; j < W; j++) {
                    area.at(h).at(j) = 1;
                }
            }
        }
        if (a == 3) {
            for (int h = 0; h < y; h++) {
                for (int j = 0; j < W; j++) {
                    area.at(h).at(j) = 1;
                }
            }
        }
        if (a == 4) {
            for (int h = y; h < H; h++) {
                for (int j = 0; j < W; j++) {
                    area.at(h).at(j) = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (area.at(i).at(j) == 0) {
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;
}
