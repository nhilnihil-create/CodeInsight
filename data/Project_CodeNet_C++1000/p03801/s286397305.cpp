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
#include <iomanip>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

const int MAX_N = 100050;
int N;
long long a[MAX_N];

std::vector<int> belong[MAX_N];
long long belong_ac[MAX_N];
long long ret[MAX_N] = {};

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }
    a[0] = 0;

    std::vector<int> cand_idx;
    cand_idx.push_back(0);
    long long tmp_max = 0;
    belong[0].push_back(0);

    for (int i = 1; i <= N; i++) {
        if (tmp_max < a[i]) {
            cand_idx.push_back(i);
            tmp_max = a[i];
            belong[cand_idx.size() - 1].push_back(i);
        } else {
            int lb = 0;
            int ub = cand_idx.size() - 1;
            while(lb + 1 < ub) {
                int mid = (lb + ub) / 2;
                if (a[i] <= a[cand_idx[mid]]) {
                    ub = mid;
                } else {
                    lb = mid;
                }
            }
            belong[ub].push_back(i);
        }
    }

    /*
    for (int i = 0; i < cand_idx.size(); i++) {
        std::cout << "cand:" << cand_idx[i] << ":";
        for (auto b : belong[i]) {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }
    */

    belong_ac[cand_idx.size()] = 0;

    for (int i = cand_idx.size() - 1; 0 <= i; i--) {
        belong_ac[i] = belong_ac[i+1] + belong[i].size();
    }

    for (int i = cand_idx.size() - 1; 1 <= i; i--) {
        for (auto b : belong[i]) {
            ret[cand_idx[i]] += a[b] - a[cand_idx[i-1]];
        }
        ret[cand_idx[i]] += (a[cand_idx[i]] - a[cand_idx[i-1]]) * belong_ac[i+1];
    }

    for (int i = 1; i <= N; i++) {
        std::cout << ret[i] << std::endl;
    }
    
    return 0;
}
