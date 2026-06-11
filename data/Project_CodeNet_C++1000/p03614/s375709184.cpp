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
#include <functional>
#include <string>

typedef __int128_t int128_t;
std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
    int64_t tmp; input >> tmp; value = tmp;
    return input;
}
std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
    output << (int64_t)value;
    return output;
}

namespace std {
    template<> class hash<int128_t>{
        public:
        size_t operator () ( const int128_t &x ) const {
            int64_t INF64 = std::numeric_limits<int64_t>::max();
            int64_t y1 = x / INF64;
            int64_t y2 = x % INF64;
            return hash<int64_t>()(y1) ^ hash<int64_t>()(y2);
        }
    };
}

int128_t imax(const int128_t a, const int128_t b) { return std::max(a, b); } // std::max, std::min は型が違うとエラーになるため、ラッパーを作る。
int128_t imin(const int128_t a, const int128_t b) { return std::min(a, b); }

#define rep(i, begin, end) for(int64_t i = ((int64_t)begin); i <= ((int64_t)end); i++) // (int64_t)end としておくと、end = v.size() - 2 みたいな入力で、v.size()が1でも正常(end = -1になる）に挙動する。
#define rev(i, begin, end) for(int64_t i = ((int64_t)begin); ((int64_t)end) <= i; i--)

#define input1(begin, end, v1) v1.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i]; }
#define input2(begin, end, v1, v2) v1.resize((end)+1); v2.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i]; } 
#define input3(begin, end, v1, v2, v3) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i]; }
#define input4(begin, end, v1, v2, v3, v4) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); v4.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i]; } 
// input_arrayはbegin = 0のときのみ動作確認。Aの要素の型をテンプレートにして関数にしたほうが丁寧かもしれない。
#define input_array(begin, N, M, A) A.resize((begin)+(N)); for (int i = 0; i < (begin)+(N); i++) { A[i].resize((begin)+(M)); } for (int i = begin; i < (begin)+(N); i++) { for (int j = begin; j < (begin)+(M); j++) { std::cin >> A[i][j]; }}

std::vector<int> irange(const int begin, const int end) {
    std::vector<int> ret; for (int i = begin; i <= end; i++) { ret.push_back(i); }
    return ret;
}

template <typename T>
void printvec(const std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;
}




//--code begin--

int128_t N;
std::vector<int128_t> p;
//std::string ;
//std::vector<std::string> ;
//double ;
//std::vector<double> ;

//const int128_t MAX_N = ;
//const int128_t MOD = ;
//const int128_t INF = std::numeric_limits<int64_t>::max();
//using pair = std::pair<int64_t, int>;

int main(int argc, char **argv) {
    std::cin >> N;

    input1(1, N, p);
    int128_t cnt = 0;
    rep (i, 1, N - 1) {
        if (p[i] == i) {
            std::swap(p[i], p[i+1]);
            cnt++;
        }
    }
    if (p[N] == N) {
        cnt++;
    }

    std::cout << cnt << std::endl;


    return 0;
}