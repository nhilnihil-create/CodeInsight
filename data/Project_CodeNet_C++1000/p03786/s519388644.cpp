//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL A[100000];

LL ans = 1;

void solve(){
    sort(A,A+N);//昇順
    //A[0]~A[j-1]までの和をaccum_A[j]とおく
    //ただしaccum_A[0] = 0と定める
    vector<LL> accum_A(N+1,0);
    for(int i=0;i<N;i++) accum_A[i+1] = accum_A[i] + A[i];

    //A[0]~A[i]までの和,accum_A[i+1]の2倍が
    //A[i+1]以上ならば（つまりi番目がi+1番目を吸収可能かどうか）
    //を各iについて判定
    for(int i=N-2;i>=0;i--){
        if(accum_A[i+1]*2>=A[i+1]){
            ans++;
        }else break;
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
 
    solve();

    cout << ans << endl;
    return 0;
}