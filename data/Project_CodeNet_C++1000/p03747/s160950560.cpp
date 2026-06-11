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



const int MAX_N = 100050;
int N;
long long L, T;
long long X[MAX_N], W[MAX_N];

long long tmp[MAX_N];
long long ret[MAX_N];

long long mod(long long loc) {
    if (0 <= loc) {
        return loc % L;
    } else {
        long long tmp = -loc / L;
        return (loc + (tmp + 1) * L) % L;
    }
}

int main(int argc, char **argv) {
    std::cin >> N >> L >> T;

    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> W[i];
    }

    int num_cc = 0;

    for (int i = 0; i < N; i++) {
        if (W[i] == 2) {
            num_cc++;
        }
    }

    if (num_cc == 0 || num_cc == N) {

        for (int i = 0; i < N; i++) {
            ret[i] = W[i] == 1 ? mod(X[i] + T) : mod(X[i] - T);
        }

    } else {
        int first_c = 0;

        for (int i = 0; i < N; i++) {
            if (W[i] == 1) {
                first_c = i;
                break;
            }
        }

        std::vector<long long> loc;

        for (int i = 0; i < N; i++) {
            loc.push_back(W[i] == 1 ? mod(X[i] + T) : mod(X[i] - T));
        }
        std::sort(loc.begin(), loc.end());

        long long pass_num = (T / L) * num_cc * 2;

        for (int i = 0; i < N; i++) {
            if (W[i] == 2) {
                if (L + mod(X[i] - X[first_c]) < (T % L) * 2) {
                    pass_num += 2;
                } else if (mod(X[i] - X[first_c]) < (T % L) * 2) {
                    pass_num += 1;
                }
            }
        }

        long long st = (first_c + pass_num) % N; // 基準点のアリID (mod N)

        long long st_tmp_idx = 0; // 基準点のアリIDのloc上のID
        for (int i = 0; i < N; i++) {
            if (loc[i] == mod(X[first_c] + T)) {
                st_tmp_idx = i;
                break;
            }
        }

        //std::cout << "check:" << st << " " << st_tmp_idx << std::endl;

        for (int i = 0; i < N; i++) {
            ret[i] = loc[(i - st + st_tmp_idx + N) % N];
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << ret[i] << std::endl;
    }

    return 0;
}
