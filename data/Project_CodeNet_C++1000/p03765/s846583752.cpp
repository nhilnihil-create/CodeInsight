#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath> // 変数名にy1が使えなくなるかも…。
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <string>

typedef __int128_t int128_t;
std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
    long long tmp; input >> tmp; value = tmp;
    return input;
}
std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
    output << (long long)value;
    return output;
}

const int MAX_N = 1e5 + 9;
const int MAX_Q = 1e5 + 9;
std::string S,T;
int q;
int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];

int acS[MAX_N], acT[MAX_N];

int main(int argc, char **argv) {
    std::cin >> S;
    std::cin >> T;
    std::cin >> q;

    for (int i = 1; i <= q; i++) {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    acS[0] = 0;
    for (int i = 1; i <= S.size(); i++) {
        acS[i] = acS[i-1] + (S[i-1] - 'A') + 1;
        //std::cout << acS[i] << " ";
    }
    //std::cout << std::endl;

    acT[0] = 0;
    for (int i = 1; i <= T.size(); i++) {
        acT[i] = acT[i-1] + (T[i-1] - 'A') + 1;
        //std::cout << acT[i] << " ";
    }
    //std::cout << std::endl;

    for (int i = 1; i <= q; i++) {
        if ((acS[b[i]] - acS[a[i]-1]) % 3 == (acT[d[i]] - acT[c[i]-1]) % 3) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}
