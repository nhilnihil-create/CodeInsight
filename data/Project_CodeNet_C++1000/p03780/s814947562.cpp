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
 
const int MAX_N = 5050;
long long N, K;
long long a[MAX_N];

bool can_make[MAX_N][MAX_N];

bool check(const int id) {
    if (K <= a[id]) {
        return true;
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            can_make[i][j] = false;
        }
    }

    can_make[0][0] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (can_make[i-1][j]) {
                can_make[i][j] = true;
            }
            if (i != id && j + a[i] <= K && can_make[i-1][j]) {
                can_make[i][j + a[i]] = true;
                //std::cout << i << " " << j + a[i] << std::endl;
            }
        }
    }

    for (int k = K - a[id]; k < K; k++) {
        if (can_make[N][k]) {
            return true;
        }
    }

    return false;
}

 
int main(int argc, char **argv) {
    std::cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + 1 + N);

    //std::cout << a[1] << " " << a[2] << " " << a[3] << std::endl;

    if (!check(N)) {
        std::cout << N << std::endl;
        return 0;
    } else if (check(1)) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int lb = 1;
    int ub = N;

    while (lb + 1 < ub) {
        int mid = (lb + ub) / 2;
        if (check(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    std::cout << lb << std::endl;
    
    return 0;
}