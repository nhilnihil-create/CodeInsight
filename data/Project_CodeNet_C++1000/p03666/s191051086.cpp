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
#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

const int MAX_K = 100050;
int N;
long long A, B, C, D;

int condition(const int n, const int m, const long long val) {
    long long lb = - D * n + (D + C) * m;
    long long ub = - C * n + (D + C) * m;

    if (lb <= val && val <= ub) {
        return 0;
    } else if (val < lb) {
        return 1;
    } else {
        return -1;
    }
}

int main(int argc, char **argv) {
    std::cin >> N >> A >> B >> C >> D;

    long long val = abs(B - A);

    if (condition(N-1, N-1, val) == 0 || condition(N-1, 0, val) == 0) {
        std::cout << "YES" << std::endl;
        return 0;
    }

    int lb = 0;
    int ub = N-1;

    while (lb + 1 < ub) {
        int mid = (lb + ub) / 2;
        int cond = condition(N-1, mid, val);

        if (cond == 0) {
            std::cout << "YES" << std::endl;
            return 0;
        } else if (cond == 1) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    if (condition(N-1, lb, val) == 0 || condition(N-1, ub, val) == 0) {
        std::cout << "YES" << std::endl;
        return 0;
    }

    std::cout << "NO" << std::endl;

    return 0;
}
