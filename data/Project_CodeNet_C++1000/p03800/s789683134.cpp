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

std::string S;
int N;
int tmp[MAX_N];

void proc() {
    for (int i = 2; i < S.size(); i++) {
        if (tmp[i-1] == 0) {
            if (S[i-1] == 'o') {
                tmp[i] = tmp[i-2];
            } else {
                tmp[i] = 1 - tmp[i-2];
            }
        } else {
            if (S[i-1] == 'o') {
                tmp[i] = 1 - tmp[i-2];
            } else {
                tmp[i] = tmp[i-2];
            }
        }
    }
}

void out() {
    std::string ret;
    for (int i = 0; i < S.size(); i++) {
        if (tmp[i] == 0) {
            ret.push_back('S');
        } else {
            ret.push_back('W');
        }
    }
    std::cout << ret << std::endl;
}

bool check(const int i) {
    int l = (i == 0) ? N - 1 : i - 1;
    int r = (i == N - 1) ? 0 : i + 1;

    if (tmp[i] == 0) {
        if (S[i] == 'o') {
            return tmp[l] == tmp[r];
        } else {
            return tmp[l] != tmp[r];
        }
    } else {
        if (S[i] == 'o') {
            return tmp[l] != tmp[r];
        } else {
            return tmp[l] == tmp[r];
        }
    }
}

int main(int argc, char **argv) {
    std::cin >> N;
    std::cin >> S;

    /*
    tmp[0] = 0;
    tmp[1] = 0;
    proc();
    out();
    */
    
    //std::cout << (int)check(0) << " " << (int)check(N-1) << std::endl;

    for (int i0 = 0; i0 <= 1; i0++) {
        for (int i1 = 0; i1 <= 1; i1++) {
            tmp[0] = i0;
            tmp[1] = i1;
            proc();

            if (check(0) && check(N-1)) {
                out();
                return 0;
            }
        }
    }

    std::cout << "-1" << std::endl;

    return 0;
}
