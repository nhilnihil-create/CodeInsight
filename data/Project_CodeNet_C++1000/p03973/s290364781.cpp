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
int N;
long long A[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    long long ret = A[1] - 1;
    long long ban = 1;
    A[1] = 1;

    for (int i = 1; i <= N; i++) {
        //std::cout << i << " " << ban << " " << ret << std::endl;
        if (A[i] <= ban) {
            // nothing to do
        } else if (A[i] == ban + 1) {
            ban++;
        } else {
            if (A[i] % (ban + 1) == 0) {
                ret += A[i] / (ban + 1) - 1;
            } else {
                ret += A[i] / (ban + 1);
            }
        }
    }

    std::cout << ret << std::endl;


    return 0;
}
