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

long long pow_mod(long long x, long long n, long long mod_num) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) { res = (res * x) % mod_num; }
        x = (x * x) % mod_num;
        n = (n >> 1);
    }
    return res;
}

const int MAX_N = 100050;
const int POW_MAX = 18;
int N, L, Q;
int x[MAX_N], a[MAX_N], b[MAX_N];
const int MOD = 1000000007;

int can_go[POW_MAX][MAX_N];

int calc(int na, int nb) {
    if (nb <= can_go[0][na]) {
        return 1;
    } else {
        for (int p = 0; p < POW_MAX; p++) {
            if (can_go[p][na] < nb && nb <= can_go[p+1][na]) {
                return pow_mod(2, p, MOD) + calc(can_go[p][na], nb);
            }
        }
    }
}

int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> x[i];
    }
    std::cin >> L;
    std::cin >> Q;
    for (int i = 1; i <= Q; i++) {
        std::cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= N; i++) {
        if (x[N] - x[i] <= L) {
            can_go[0][i] = N;
        } else {
            int lb = i + 1;
            int ub = N;
            while (lb + 1 < ub) {
                int mid = (lb + ub) / 2;
                if (x[mid] - x[i] <= L) {
                    lb = mid;
                } else {
                    ub = mid;
                }
            }
            can_go[0][i] = lb;
        }
        //std::cout << 0 << " " << i << " " << can_go[0][i] << std::endl;
    }

    for (int p = 1; p < POW_MAX; p++) {
        for (int i = 1; i <= N; i++) {
            can_go[p][i] = can_go[p-1][can_go[p-1][i]];
            //std::cout << p << " " << i << " " << can_go[p][i] << std::endl;
        }
    }

    for (int i = 1; i <= Q; i++) {
        std::cout << calc(std::min(a[i], b[i]), std::max(a[i], b[i])) << std::endl;
    }
    
    return 0;
}