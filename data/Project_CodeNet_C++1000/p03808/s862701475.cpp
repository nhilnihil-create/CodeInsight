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
int N;
long long A[MAX_N];

bool solve() {
    if (N == 1) {
        return true;
    }

    long long one_proc_num = 0;
    long long total = 0;
    long long min = A[1];

    for (int i = 1; i <= N; i++) {
        total += A[i];
        one_proc_num += i;
        min = std::min(min, A[i]);
    }

    if (total % one_proc_num != 0) {
        return false;
    }

    long long NP = total / one_proc_num;

    if (min < NP) {
        return false;
    }

    long long tmp_proc_num = 0;
    for (int i = 1; i <= N; i++) {
        long long tmp = A[i] + NP;
        int next = i == N ? 1 : i + 1;
        if (tmp < A[next]) {
            return false;
        } else if ((tmp - A[next]) % N != 0) {
            return false;
        } else {
            tmp_proc_num += (tmp - A[next]) / N;
        }
    }
    return tmp_proc_num == NP;
}

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    if (solve()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}