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
#include <iomanip>
#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

const int MAX_N = 550;
int A[MAX_N][MAX_N] = {};
int H, W, h, w;

const int LARGE = 5000000;

bool solve() {
    if (H % h == 0 && W % w == 0) {
        return false;
    }

    if (H % h == 0) {
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (j % w == 1) {
                    A[i][j] = LARGE;
                } else if (j % w == 0) {
                    A[i][j] = - LARGE - 1;
                }
            }
        }
    } else if (W % w == 0) {
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (i % h == 1) {
                    A[i][j] = LARGE;
                } else if (i % h == 0) {
                    A[i][j] = - LARGE - 1;
                }
            }
        }
    } else {
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (i % h == 1 && j % w == 1) {
                    A[i][j] = LARGE;
                } else if (i % h == 0 && j % w == 0) {
                    A[i][j] = LARGE - 1;
                } else if (i % h == 1 && j % w == 0) {
                    A[i][j] = - LARGE;
                } else if (i % h == 0 && j % w == 1) {
                    A[i][j] = - LARGE;
                }
            }
        }
    }
    return true;

}

int main(int argc, char **argv) {
    std::cin >> H >> W >> h >> w;

    if (solve()) {
        std::cout << "Yes" << std::endl;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                std::cout << A[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}