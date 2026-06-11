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

long long pow_mod(long long x, long long n, long long mod_num) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) { res = (res * x) % mod_num; }
        x = (x * x) % mod_num;
        n = (n >> 1);
    }
    return res;
}


const int MAX_N = 5010;
const long long MOD = 1000000007;
int N;
std::string s;

//Combi_Num combi_num = Combi_Num(MAX_N, MOD);

long long dp00[MAX_N][MAX_N] = {}; // dp00[i][j] i回入力してj文字
 
int main(int argc, char **argv) {
    std::cin >> N;
    std::cin >> s;

    dp00[0][0] = 1;
    //dp01[0][0] = 1;

    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp00[i+1][j] = (dp00[i+1][j] + dp00[i][j]) % MOD;
            } else {
                dp00[i+1][j-1] = (dp00[i+1][j-1] + dp00[i][j]) % MOD;
                //dp01[i+1][j-1] = (dp01[i+1][j-1] + dp01[i][j]) % MOD;
            }
            dp00[i+1][j+1] = (dp00[i+1][j+1] + dp00[i][j] * 2) % MOD;
            //dp01[i+1][j+1] = (dp01[i+1][j+1] + dp01[i][j] * 2) % MOD;
        }
    }

    long long ret = dp00[N][s.size()];
    long long inv2 = pow_mod(2, MOD - 2, MOD);
    for (int i = 0; i < s.size(); i++) {
        ret = (ret * inv2) % MOD;
    }
    std::cout << ret << std::endl;

    return 0;
}