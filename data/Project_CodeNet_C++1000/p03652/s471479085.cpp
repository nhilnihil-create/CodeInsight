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
#include <bitset>
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

const int MAX_N = 310;
const int MAX_M = 310;
int N, M;
int A[MAX_N][MAX_M];

std::pair<int, int> count(std::bitset<MAX_M> bs) {
    int cnt[MAX_M] = {};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (bs.test(A[i][j])) {
                cnt[A[i][j]]++;
                break;
            }
        }
    }

    int s = 0;
    int max = 0;
    for (int j = 1; j <= M; j++) {
        if (max < cnt[j]) {
            s = j;
            max = cnt[j];
        }
    }
    return std::pair<int, int>({s, max});
}

int main(int argc, char **argv) {
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        A[i][0] = MAX_M;
        for (int j = 1; j <= M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::bitset<MAX_M> bs;

    for (int i = 1; i <= M; i++) {
        bs.set(i);
    }

    int ret = N;
    while (0 < bs.count()) {
        std::pair<int, int> cnt = count(bs);
        ret = std::min(ret, cnt.second);
        bs.reset(cnt.first);
    }

    std::cout << ret << std::endl;
    
    return 0;
}