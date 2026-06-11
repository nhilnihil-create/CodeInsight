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
#include <map>
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

const int MAX_N = 100050;
int N, T;
long long A[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }
    
    int num;
    int min = A[1];
    int max_d = 0;
    for (int i = 2; i <= N; i++) {
        if (min + max_d < A[i]) {
            num = 1;
            max_d = A[i] - min;
        } else if (min + max_d == A[i]) {
            num++;
        }
        if (A[i] < min) {
            min = A[i];
        }
    }

    std::cout << num << std::endl;

    
    return 0;
}
