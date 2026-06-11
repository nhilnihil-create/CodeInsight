/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
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
//#include <unordered_set> //unordered_set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 100100100100;
const long long MOD = 1000000007;
typedef pair<int,int> P;

//Solve N^M. This, mod_pow use Iterative Square Method.
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    int H,W,N;cin >> H >> W >> N;swap(H,W);
    vector<vector<bool>> retu(H,vector<bool>(W)); 
    for(int i = 0;i<N;i++){
        int x,y,a;cin >> x >> y >> a;
        if(a == 1){
            for(int j = 0;j<H;j++){
                for(int k = 0;k<x;k++){
                    retu.at(j).at(k) = true;
                }
            }
        }
        else if(a == 2){
            for(int j = 0;j<H;j++){
                for(int k = x;k<W;k++){
                    retu.at(j).at(k) = true;
                }
            }
        }
        else if(a == 3){
            for(int j = 0;j<y;j++){
                for(int k = 0;k<W;k++){
                    retu.at(j).at(k) = true;
                }
            }
        }
        else if(a == 4){
            for(int j = y;j<H;j++){
                for(int k = 0;k<W;k++){
                    retu.at(j).at(k) = true;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<H;i++)for(int j = 0;j<W;j++) if(!retu.at(i).at(j)) ans++;
    cout << ans << endl;
}
