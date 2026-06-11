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

long long calc_simple(long long aI, long long aO, long long aJ, long long aL) {
    return aO * 2 + (aI / 2) * 4 + (aJ / 2) * 4 + (aL / 2) * 4;
}

int main(int argc, char **argv) {
    long long aI, aO, aT, aJ, aL, aS, aZ;
    std::cin >> aI >> aO >> aT >> aJ >> aL >> aS >> aZ;

    long long three_min = std::min(std::min(aJ, aL), aI);

    long long ret = 0;
    if (three_min == 0) {
        std::cout << calc_simple(aI, aO, aJ, aL) / 2 << std::endl;
        return 0;
    }

    long long tmp1 = three_min * 6 + calc_simple(aI - three_min, aO, aJ - three_min, aL - three_min);
    long long tmp2 = (three_min - 1) * 6 + calc_simple(aI - three_min + 1, aO, aJ - three_min + 1, aL - three_min + 1);

    std::cout << std::max(tmp1, tmp2) / 2 << std::endl;

    return 0;
}
