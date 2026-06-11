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

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

const int MAX_N = 150;

int N;
int a[MAX_N], dist_num[MAX_N] = {};

bool solve() {
    int max_dist = a[1];
    int min_dist = a[1];
    for (int i = 1; i <= N; i++) {
        dist_num[a[i]]++;
        max_dist = std::max(max_dist, a[i]);
        min_dist = std::min(min_dist, a[i]);
    }

    if (N == 2) {
        return dist_num[1] == 2;
    }

    //if (dist_num[max_dist] == 1) {
    //    return false;
    //}

    for (int i = min_dist + 1; i <= max_dist; i++) {
        if (dist_num[i] < 2) {
            return false;
        }
    }

    if (max_dist % 2 == 0) {
        if ((min_dist == max_dist / 2) && dist_num[min_dist] == 1) {
            return true;
        } else {
            return false;
        }
    } else {
        //std::cout << "check:" << min_dist << " " << max_dist << " " << dist_num[min_dist] << std::endl;
        if ((min_dist == max_dist / 2 + 1) && dist_num[min_dist] == 2) {
            return true;
        } else {
            return false;
        }
    }
}

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    if (solve()) {
        std::cout << "Possible" << std::endl;
    } else {
        std::cout << "Impossible" << std::endl;
    }

    return 0;
}

