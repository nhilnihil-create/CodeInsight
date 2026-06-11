#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

const int MAX_N = 100050;
long long W, H;
long long p[MAX_N], q[MAX_N];

int main(int argc, char **argv) {
    std::cin >> W >> H;

    for (int i = 0; i < W; i++) {
        std::cin >> p[i];
    }

    for (int i = 0; i < H; i++) {
        std::cin >> q[i];
    }

    std::vector<std::pair<int, int>> vec;

    for (int i = 0; i < W; i++) {
        vec.push_back(std::pair<int, int>({p[i], 0}));
    }
    for (int i = 0; i < H; i++) {
        vec.push_back(std::pair<int, int>({q[i], 1}));
    }

    std::sort(vec.begin(), vec.end());
    int sel_w = 0;
    int sel_h = 0;
    long long ret = 0;
    for (auto p : vec) {
        if (p.second == 0) {
            if (H + 1 - sel_h > 0) {
                ret += (H + 1 - sel_h) * p.first;
            }
            sel_w++;
        } else {
            if (W + 1 - sel_w > 0) {
                ret += (W + 1 - sel_w) * p.first;
            }
            sel_h++;
        }
    }

    std::cout << ret << std::endl;


    return 0;
}
