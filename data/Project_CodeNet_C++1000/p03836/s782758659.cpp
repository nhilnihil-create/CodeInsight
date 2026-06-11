/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
#define WOULD
#define YOU
#define PLEASE
#define ACCEPT
#define MY
#define SUBMISSION
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
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
    int A,B,C,D;cin >> A >> B >> C >> D;
    string ans = "";
    //一回目の行き
    if(B < D){
        for(int i = 0;i<D-B;i++){
            ans += 'U';
        }
    }
    else{
        for(int i = 0;i<B-D;i++){
            ans += 'D';
        }
    }
    if(A < C){
        for(int i = 0;i<C-A;i++){
            ans += 'R';
        }
    }
    else{
        for(int i = 0;i<A-C;i++){
            ans += 'L';
        }
    }
    //一回目の帰り
    if(B > D){
        for(int i = 0;i<B-D;i++){
            ans += 'U';
        }
    }
    else{
        for(int i = 0;i<D-B;i++){
            ans += 'D';
        }
    }
    if(A < C){
        for(int i = 0;i<C-A;i++){
            ans += 'L';
        }
    }
    else{
        for(int i = 0;i<A-C;i++){
            ans += 'R';
        }
    }
    //二回目は大周りする
    if(A < C){
        ans += 'L';
        if(B < D){
            for(int i = 0;i<D-B+1;i++){
                ans += 'U';
            }
        }
        else{
            for(int i = 0;i<B-D+1;i++){
                ans += 'D';
            }
        }
        for(int i = 0;i<C-A+1;i++){
            ans += 'R';
        }
        if(B < D){
            ans += 'D';
        }
        else ans += 'U';
    }
    else{
        ans += 'R';
        if(B < D){
            for(int i = 0;i<D-B+1;i++){
                ans += 'U';
            }
        }
        else{
            for(int i = 0;i<B-D+1;i++){
                ans += 'D';
            }
        }
        for(int i = 0;i<A-C+1;i++){
            ans += 'L';
        }
        if(B < D){
            ans += 'D';
        }
        else ans += 'U';
    }
    //二回目帰り
    if(A < C){
        ans += 'R';
        if(B < D){
            for(int i = 0;i<D-B+1;i++){
                ans += 'D';
            }
        }
        else{
            for(int i = 0;i<B-D+1;i++){
                ans += 'U';
            }
        }
        for(int i = 0;i<C-A+1;i++){
            ans += 'L';
        }
        if(B < D){
            ans += 'U';
        }
        else ans += 'D';
    }
    else{
        ans += 'L';
        if(B < D){
            for(int i = 0;i<D-B+1;i++){
                ans += 'D';
            }
        }
        else{
            for(int i = 0;i<B-D+1;i++){
                ans += 'U';
            }
        }
        for(int i = 0;i<A-C+1;i++){
            ans += 'R';
        }
        if(B < D){
            ans += 'U';
        }
        else ans += 'D';
    }
    
    cout << ans << endl;
    



}