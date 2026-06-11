#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
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

const int MAX_N = 200050;
std::string A;
int memo[MAX_N];

int cal_length_from(const int begin) {
    if (memo[begin] != -1) {
        return memo[begin];
    }

    bool array[26] = {};
    int ret = 1;
    int num = 0;
    for (int i = begin; i < A.size(); i++) {
        if (!array[A[i] - 'a']) {
            array[A[i] - 'a'] = true;
            num++;
            if (num == 26) {
                ret += cal_length_from(i + 1);
                break;
            }
        }
    }
    memo[begin] = ret;
    return ret;
}

int main(int argc, char **argv) {
    std::cin >> A;

    for (int i = 0; i < MAX_N; i++) {
        memo[i] = -1;
    }

    int length = cal_length_from(0);

    //std::cout << "length:" << length << std::endl;

    std::string ret;
    int begin = 0;
    for (int i = 0; i < length; i++) {
        bool pushed = false;
        for (char tmp = 'a'; tmp <= 'z'; tmp++) {
            bool found = false;
            for (int j = begin; j < A.size(); j++) {
                if (A[j] == tmp) {
                    found = true;
                    if (cal_length_from(j+1) == length - i - 1) {
                        //std::cout << i << " " << begin << " " << tmp << " " << j + 1 << " " << length - i - 1 << std::endl;
                        ret.push_back(tmp);
                        begin = j + 1;
                        pushed = true;
                    }
                    break;
                }
            }
            if (i == length - 1 && !found) {
                ret.push_back(tmp);
                break;
            }
            if (pushed) {
                break;
            }
        }
    }
    std::cout << ret << std::endl;

    return 0;
}
