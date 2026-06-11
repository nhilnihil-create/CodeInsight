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
int N;
long long A[MAX_N];
long long ac[MAX_N];
char op[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        std::cin >> A[i] >> op[i];
    }
    std::cin >> A[N];

    std::vector<int> pos;

    for (int i = 1; i <= N; i++) {
        if (op[i] == '-') {
            pos.push_back(i+1);
        }
        ac[i] = ac[i-1] + A[i]; 
    }

    if (pos.size() == 0) {
        std::cout << ac[N] << std::endl;
        return 0;
    }

    std::vector<long long> cand;
    long long tmp = 0;
    for (int i = 0; i < pos.size(); i++) {
        if (i < pos.size() - 1) {
            //std::cout << "check:" << pos[i] << " " << pos[i+1] << " " << ac[pos[i+1] - 1] << " " << ac[pos[i] - 1] << std::endl;
            cand.push_back(tmp + ac[pos[i+1] - 1] - ac[pos[i] - 1]);
        }
        tmp += A[pos[i]];
    }
    cand.push_back(tmp);

    std::sort(cand.begin(), cand.end());

    std::cout << ac[N] - cand[0] * 2 << std::endl;
    
    return 0;
}