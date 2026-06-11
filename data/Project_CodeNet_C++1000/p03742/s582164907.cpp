//#include <bits/stdc++.h>
//#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstring>
#include<bitset>

#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define mset(var,val) memset(var,val,sizeof(var))
#define IOS ios::sync_with_stdio(false);cin.tie(0)

#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)

using namespace std;
typedef long long ll;

#ifdef local
#define dbg(args...) do { cout << "\033[32;1m" << #args << " -> "; err(args); } while (0)
void err() {
    cout << "\033[39;0m" << endl;
}
template<template<typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args) {
    for (auto x: a)
        cout << x << ' ';
    err(args...);
}
template<typename T, typename... Args>
void err(T a, Args... args) {
    cout << a << ' ';
    err(args...);
}
#else
#define dbg(...)
#endif

const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const long double eps = 1e-6;
const int mod = 998244353;
const int maxn = 3e6;
const int N = 1e5+5;
const int M = 1e5+5;
const int NN = 1e3+5;

int _ = 0;
void testcase() {
    cout << "Case " << (++_) << ": ";
//    printf("Case %d: ", ++_);
}

typedef pair<int,int> pii;

//int dp[30][30];
//
//int getsg(int i, int j){
//    if(~dp[i][j])return dp[i][j];
//    vector<int> mex;
//    for(int k = 1; k <= i/2; ++k){
//        mex.PB(getsg(i-2*k, j+k));
//    }
//    for(int k = 1; k <= j/2; ++k){
//        mex.PB(getsg(i+k, j-2*k));
//    }
//    int &ans = dp[i][j];
//    ans = mex.size();
//    sort(mex.begin(), mex.end());
//    rep(k,mex.size()){
//        if(k != mex[k]){
//            ans = k;
//            break;
//        }
//    }
//    return ans;
//}


void work() {
//    mset(dp,-1);
//    dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;
//    for(int i = 0; i <= 10; ++i){
//        for(int j = 0; j <= 10; ++j){
//            dbg(i,j,getsg(i,j));
//        }
//    }
    ll x, y;
    cin >> x >> y;
    if(x < y) swap(x,y);
    if(x >= y+2){
        cout << "Alice\n";
    }
    else{
        cout << "Brown\n";
    }

}


int main() {
#ifdef local
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // local
    IOS;
//    init();


//     int t;
//
//     cin >> t;
//     for(;t--;)
    work();

    return 0;
}
