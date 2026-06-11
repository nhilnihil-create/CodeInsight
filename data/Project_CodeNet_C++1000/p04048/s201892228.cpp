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

long long calc(long long l1, long long l2) {
    // l1 >= l2
    if (l1 % l2 == 0) {
        return l2 * ((l1 / l2) * 2 - 1);
    } else {
        return l2 * (l1 / l2) * 2 + calc(l2, l1 % l2);
    }
}

long long N, X;

int main(int argc, char **argv) {
    std::cin >> N >> X;

    long long ret = N + calc(std::max(X, N - X), std::min(X, N - X));

    std::cout << ret << std::endl;
    
    return 0;
}