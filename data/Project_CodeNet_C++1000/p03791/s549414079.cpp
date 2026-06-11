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
const int MOD = 1000000007;
int N, x[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> x[i];
    }

    int num = 0;
    long long ret = 1;
    for (int i = 1; i <= N; i++) {
        if (num * 2 + 1 <= x[i]) {
            num++;
        } else {
            ret = (ret * (num + 1)) % MOD;
        }
    }

    for (int i = 1; i <= num; i++) {
        ret = (ret * i) % MOD;
    }

    
    std::cout << ret << std::endl;

    return 0;
}
