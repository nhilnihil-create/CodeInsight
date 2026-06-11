/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    WRITER:kakitamasziru/OxOmisosiru
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#define _GLIBCXX_DEBUG
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip>
#include <limits>//setprecision
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
//#include <unordered_map> // unordered_map
//#include <unordered_set> // unordered_set
#include <bitset> // bitset
//#include <cctype> // isupper, islower, isdigit, toupper, tolower
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 100100100100100;
const int MOD = 1000000007;
typedef pair<int,int> P;
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

int main() {
    string S;cin >> S;
    set<char> NS;
    for(int i = 0;i<S.size();i++){
        if(S.at(i) == 'N') NS.insert(S.at(i));
        else if(S.at(i) == 'S') NS.insert(S.at(i));
    }
    set<char> WE;
    for(int i = 0;i<S.size();i++){
        if(S.at(i) == 'W') WE.insert(S.at(i));
        else if(S.at(i) == 'E') WE.insert(S.at(i));
    }
    if(NS.count('N') && NS.count('S') || (!NS.count('N') && !NS.count('S'))){
        if(WE.count('W') && WE.count('E') || (!WE.count('W') && !WE.count('E'))){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    
    // PLEASE GIVE ME THE "ACCEPTED" !
}