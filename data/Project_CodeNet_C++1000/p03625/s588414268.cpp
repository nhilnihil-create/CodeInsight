#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#define _GLIBCXX_DEBUG
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <iomanip>
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1001001000;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

using Graph = vector<vector<int>>;
//再帰とかグラフを使うときは予めNの最大値のグローバル配列を取っておく


//NのM乗を求める(繰り返し二乗法)
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}
long long nCr(long long n, long long r) {
    long long A = 1, B = 1;
    //Aが分子Bが1/r!
    for (long long i = n - r + 1; i <= n; i++) {
        A = A * i % MOD;
    }
    for (long long i = 1; i <= r; i++) {
        B = B * i % MOD;
    }
    B = mod_pow(B, MOD - 2);
    B %= MOD;
    //Bは割るのではなく掛ける
    return (A * B) % MOD;
}

bool E[2005][2005];
vector<bool> seen;
typedef pair<int, int> P;
int D[2005];
//頂点状態を表すcolor[]において、0は未訪問、1は訪問中、2は完了を表す。
int color[101];
int find_time = 0;

int main() {
    int N; cin >> N;
    vector<long long> hen(N);
    vector<long long> canUse(114514);
    for (int i = 0; i < N; i++) cin >> hen.at(i);
    sort(hen.begin(), hen.end());
    int sameCount = 1;
    for (int i = 0; i < N-1; i++) {
        if (hen.at(i) == hen.at(i + 1)) {
            sameCount++;
        }
        else sameCount = 1;
        if (sameCount == 2) { 
            canUse.push_back(hen.at(i)); 
            sameCount = 0;
        }
    }
    sort(canUse.begin(), canUse.end());
    reverse(canUse.begin(), canUse.end());

    cout << canUse.at(0) * canUse.at(1) << endl;
}
