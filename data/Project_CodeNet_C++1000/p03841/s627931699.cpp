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

const int MAX_N = 510;
int N, x[MAX_N];
int ret[MAX_N * MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> x[i];
    }

    std::vector<int> vec;
    for (int i = 1; i <= N; i++) {
        vec.push_back(i);
    }
    std::sort(vec.begin(), vec.end(), 
        [](const int a, const int b) { return x[a] < x[b]; }
    );

    std::queue<int> left_que, right_que;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 1; j <= vec[i] - 1; j++) {
            left_que.push(vec[i]);
        }
    }

    for (int i = vec.size() - 1; 0 <= i; i--) {
        for (int j = vec[i] + 1; j <= N; j++) {
            right_que.push(vec[i]);
        }
    }

    for (int i = 1; i <= N; i++) {
        ret[x[i]] = i;
    }

    int pos = 1;
    while (!left_que.empty()) {
        if (ret[pos] == 0) {
            int i = left_que.front(); left_que.pop();
            if (x[i] < pos) {
                std::cout << "No" << std::endl;
                return 0;
            }
            ret[pos] = i;
        }
        pos++;
    }

    pos = N * N;
    while (!right_que.empty()) {
        if (ret[pos] == 0) {
            int i = right_que.front(); right_que.pop();
            if (pos < x[i]) {
                std::cout << "No" << std::endl;
                return 0;
            }
            ret[pos] = i;
        }
        pos--;
    }

    std::cout << "Yes" << std::endl;
    for (int i = 1; i <= N*N; i++) {
        std::cout << ret[i] << " ";
    }


    return 0;
}