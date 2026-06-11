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

long long pow_mod(long long x, long long n, long long mod_num) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) { res = (res * x) % mod_num; }
        x = (x * x) % mod_num;
        n = (n >> 1);
    }
    return res;
}

class Combi_Num {
    public:
    long long mod_num;
    std::vector<long long> factorial, factorial_inv, inv;
    Combi_Num() {}
    Combi_Num(const int n, const long long mod_num_in) {
        mod_num = mod_num_in;
        factorial.resize(n+1, 0);
        factorial_inv.resize(n+1, 0);
        inv.resize(n+1, 0);
        factorial[0] = 1;
        factorial_inv[0] = 1;
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i-1] * i) % mod_num;
            inv[i] = pow_mod(i, mod_num - 2, mod_num);
            factorial_inv[i] = (factorial_inv[i-1] * inv[i]) % mod_num;
        }
    }

    /*
    long long combi(const int n, const int r) {
        return (factorial[n] * ((factorial_inv[r] * factorial_inv[n-r]) % mod_num)) % mod_num;
    }
    */

    long long combi(const int n, const int r) {
        long long ret = 1;
        for (int i = 1; i <= r; i++) {
            ret = ret * (n - i + 1) / i;
        }
        return ret;
    }

    long long perm(const int n, const int r) {
        return (factorial[n] * factorial_inv[n-r]) % mod_num;
    }
};

const long long MOD = 1000000007;
const int MAX_N = 1000;
long long N;

Combi_Num combi_num = Combi_Num(MAX_N, MOD);

long long calc(const std::vector<int>& vec, int test) {

    std::vector<long long> ac;
    ac.push_back(1);
    for (int val : vec) {
        std::vector<long long> ac_new;
        for (int i = 0; i <= val; i++) {
            for (long long v : ac) {
                ac_new.push_back(v * combi_num.combi(val, i));
            }
        }
        ac = ac_new;
    }

    long long ret = 0;
    for (int i = 0; i <= test; i++) {
        for (long long v : ac) {
            ret += v * combi_num.combi(test, i) * v * combi_num.combi(test, i);
        }
    }
    ret -= 1;

    long long sub = 0;
    long long add = 0;
    for (int i : vec) {
        for (int j = 1; j <= i; j++) {
            sub = sub + combi_num.combi(i, j) * combi_num.combi(i, j);
            add = add + combi_num.combi(i*2, j*2);
        }
    }
    for (int j = 1; j <= test; j++) {
        sub = sub + combi_num.combi(test, j) * combi_num.combi(test, j);
        add = add + combi_num.combi(test*2, j*2);
    }

    return ret - sub + add;
}

long long calc2 (int num1, int num2) {
    long long ret = 0;
    for (int j = 2; j <= num1 + num2; j += 2) {
        ret += combi_num.combi(num1 + num2, j);
    }

    for (int j = 1; j <= std::min(num1, num2); j++) {
        ret += combi_num.combi(num1, j) * combi_num.combi(num2, j);
    }

    return ret + 1;
}

long long calc3 (int num1, int num2, int num3, int num4) {
    long long ret = 0;
    for (int j = 2; j <= num1 + num2; j += 2) {
        ret += combi_num.combi(num1 + num2, j);
    }
    for (int j = 2; j <= num3 + num4; j += 2) {
        ret += combi_num.combi(num3 + num4, j);
    }

    for (int j = 1; j <= std::min(num1, num2); j++) {
        for (int k = 1; k <= std::min(num3, num4); k++) {
            ret += combi_num.combi(num1, j) * combi_num.combi(num2, j) * combi_num.combi(num3, k) * combi_num.combi(num4, k);
        }
    }
    return ret;
}

int main(int argc, char **argv) {
    std::cin >> N;
    
    /*
    int base = 6;
    std::vector<int> vec;
    std::cout << calc(vec, base) << std::endl;
    std::cout << calc3(base, base, 1, 1) << std::endl;
    std::cout << calc3(base, base, 2, 2) << std::endl;

    for (int i = 0; i <= base; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= j; k++) {
                std::cout << base + i << " " << base - i << " " << j << " " << k << " " << calc3(base + i, base - i, j, k) << std::endl;
            }
        }
    }
    */

    std::vector<std::vector<int>> ret_vec;
    while (0 < N) {
        std::vector<int> vec;
        int num;
        for (int i = 1; i <= 100; i++) {
            if (N < calc(vec, i)) {
                num = i - 1;
                break;
            }
        }
        long long cm = calc(vec, num);
        vec.resize(4, 0);
        vec[0] = num; vec[1] = num;
        for (int i = 0; i <= num; i++) {
            for (int j = 1; j <= 5; j++) {
                for (int k = 1; k <= j; k++) {
                    long long tmp = calc3(num + i, num - i, j, k);
                    if (cm < tmp && tmp <= N) {
                        cm = tmp;
                        vec[0] = num + i;
                        vec[1] = num - i;
                        vec[2] = j;
                        vec[3] = k;
                    }
                }
            }
        }
        N -= cm;
        ret_vec.push_back(vec);
    }

    std::vector<int> ret;
    int num = 1;
    for (auto vec : ret_vec) {
        for (int i = 0; i < vec[0]; i++) {
            ret.push_back(num);
        }
        for (int i = 0; i < vec[2]; i++) {
            ret.push_back(num + 1);
        }
        for (int i = 0; i < vec[1]; i++) {
            ret.push_back(num);
        }
        for (int i = 0; i < vec[3]; i++) {
            ret.push_back(num + 1);
        }
        num += 2;
    }
    std::cout << ret.size() << std::endl;
    for (int i : ret) {
        std::cout << i << " ";
    }
    return 0;

    /*
    int total = 0;
    for (auto vec : ret_vec) {
        std::cout << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << std::endl;
        total += vec[0] + vec[1] + vec[2] + vec[3];
    }
    std::cout << total << std::endl;
    */
    
    /*
    std::vector<std::vector<int>> ret_vec;
    while (0 < N) {
        std::vector<int> vec;
        while (true) {
            if (calc(vec, 1) > N) {
                N -= calc(vec, 0);
                break;
            }

            for (int i = 1; i <= 100; i++) {
                if (N < calc(vec, i)) {
                    vec.push_back(i - 1);
                    break;
                }
            }
        }
        ret_vec.push_back(vec);
    }

    int num = 1;
    std::vector<int> ret;
    for (auto vec : ret_vec) {
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < vec.size(); i++) {
                for (int j = 0; j < vec[i]; j++) {
                    ret.push_back(num + i);
                }
            }
        }
        num += vec.size();
    }

    std::cout << ret.size() << std::endl;
    for (int i : ret) {
        std::cout << i << " ";
    }
    */

    //return 0;
}
