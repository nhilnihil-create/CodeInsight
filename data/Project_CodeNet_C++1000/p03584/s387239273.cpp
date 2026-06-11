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

const int MAX_BIT = 32;
const int MAX_N = 100010;
int N;
long long K, A[MAX_N], B[MAX_N];

long long value(std::bitset<MAX_BIT> bs) {
    long long ret = 0;
    for (int i = 1; i <= N; i++) {
        if ((bs | std::bitset<MAX_BIT>(A[i])) == bs) {
            ret += B[i];
        }
    }
    return ret;
}

int main(int argc, char **argv) {
    std::cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::bitset<MAX_BIT> bs(K);

    long long ret = value(bs);

    for (int i = 0; i < MAX_BIT; i++) {
        if (bs.test(i)) {
            std::bitset<MAX_BIT> tmp = bs;
            tmp.reset(i);
            for (int j = 0; j < i; j++) {
                tmp.set(j);
            }
            ret = std::max(ret, value(tmp));
        }
    }

    std::cout << ret << std::endl;

    return 0;
}