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

const int MAX_N = 100050;
int N, K;
long long a[MAX_N];

long long ac[MAX_N], seg[MAX_N];
long long ideal_until[MAX_N], ideal_from[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    ac[0] = 0;
    ideal_until[0] = 0;

    for (int i = 1; i <= N; i++) {
        ac[i] = ac[i-1] + a[i];
        ideal_until[i] = ideal_until[i-1] + std::max(a[i], (long long)0);
    }

    for (int i = 1; i <= N - K + 1; i++) {
        seg[i] = ac[i + K - 1] - ac[i - 1];
    }

    ideal_from[N+1] = 0;
    for (int i = N; 1 <= i; i--) {
        ideal_from[i] = ideal_from[i+1] + std::max(a[i], (long long)0);
    }

    long long ret = 0;

    for (int i = 1; i <= N - K + 1; i++) {
        ret = std::max(ret, std::max(seg[i], (long long)0) + ideal_until[i-1] + ideal_from[i + K]);
    }

    std::cout << ret << std::endl;

    return 0;
}