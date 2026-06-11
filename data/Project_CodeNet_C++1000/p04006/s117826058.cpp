#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
using namespace std;
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

int main(){
    long long N,x; cin >> N >> x;
    long long a[2020];
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    long long dp[2020][2020] = {0};
    long long ans = 1e18;
    for (int i = 0; i < N; i++){
        dp[0][i] = a[i];
    }
    for (int i = 1; i < N; i++){
        for (int j = 0; j < N; j++){
            dp[i][j] = min(a[(j - i + N) % N], dp[(i-1+N) % N][j]);
        }
    }
    for (int i = 0; i < N; i++){
        long long tmp = 0;
        for (int j = 0; j < N; j++){
            tmp += dp[i][j];
        }
        ans = min(ans,i*x + tmp);
    }
    cout << ans << endl;
}