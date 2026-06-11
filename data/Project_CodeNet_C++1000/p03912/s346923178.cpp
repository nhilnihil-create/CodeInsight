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

const int MAX_N = 100050;
int N, M;
int X[MAX_N];

long long card_num[MAX_N], mod_num[MAX_N], mod_pair_num[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        std::cin >> X[i];
    }

    for (int i = 1; i <= N; i++) {
        card_num[X[i]]++;
    }

    for (int i = 1; i < MAX_N; i++) {
        mod_num[i%M] += card_num[i];
        mod_pair_num[i%M] += card_num[i] / 2;
    }

    long long ret = 0;
    for (int i = 0; i * 2 <= M; i++) {
        if (i == 0 || i * 2 == M) {
            ret += mod_num[i] / 2;
        } else {
            long long tmp = std::min(mod_num[i], mod_num[M-i]);
            ret += tmp;
            ret += std::min((mod_num[i] - tmp) / 2, mod_pair_num[i]);
            ret += std::min((mod_num[M-i] - tmp) / 2, mod_pair_num[M-i]);
        }
    }

    std::cout << ret << std::endl;

    return 0;
}

