#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath> // 変数名にy1が使えなくなるかも…。
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <string>

typedef __int128_t int128_t;
std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
    long long tmp; input >> tmp; value = tmp;
    return input;
}
std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
    output << (long long)value;
    return output;
}

int128_t cal_mod(const int128_t n, const int128_t mod) {
    // n % modを計算する。ただしmod <= 0 ならば何もしない。nが負の場合、正にして補正する。
    if (mod <= 0) {
        return n;
    } else if (0 <= n) {
        return n % mod;
    } else {
        int128_t tmp = (-n) / mod + 1;
        return (n + tmp * mod) % mod;
    }
}

int H, W, d;

int cal(int x, int y) {
    int x_mod = cal_mod(x, d * 2);
    int y_mod = cal_mod(y, d * 2);
    return x_mod / d + (y_mod / d) * 2; 
}



int main(int argc, char **argv) {
    std::cin >> H >> W >> d;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            int c = cal(i + j, i - j);
            if (c == 0) {
                std::cout << 'R';
            } else if (c == 1) {
                std::cout << 'Y';
            } else if (c == 2) {
                std::cout << 'G';
            } else {
                std::cout << 'B';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

