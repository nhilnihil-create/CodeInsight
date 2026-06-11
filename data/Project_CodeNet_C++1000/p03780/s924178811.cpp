// #include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <climits>
#include <string>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include<unordered_map>
#include <stack>
#include <random>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mapa make_pair
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
void vdeb(std::vector<T> &da) {
    for (int i = 0;i < da.size();i++) {
        if (i == da.size() - 1) std::cout << da[i];
        else std::cout << da[i] << ' ';
    }
    std::cout << std::endl;
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
    for (int i = 0;i < da.size();i++) vdeb(da[i]);
    std::cout << std::endl;
}

using namespace std;

const int CC = 5500;

int main(){
    int n, k; cin >> n >> k;
    vector<bitset<CC>> pre(n+1), bac(n+1);
    vector<int> da(n);
    rip(i,n,0) cin >> da[i];
    pre[0][0] = 1;
    bac[n][0] = 1;
    rip(i,n,0){
        pre[i+1] = pre[i];
        if(da[i] <= k) pre[i+1] |= (pre[i] << da[i]);
    }
    rip(i,n,0){
        bac[n-i-1] = bac[n-i];
        if(da[n-i-1] <= k) bac[n-i-1] |= (bac[n-i] << da[n-i-1]);
    }
    int ans = 0;
    rip(i,n,0){
        auto &now1 = pre[i], &now2 = bac[i+1];
        int co = 0;
        rip(j, k, max(0, k-da[i])){
            if(now1[j]) ++co;
        }
        bool flag = false;
        rip(j,k,0){
            if(now2[j] && co > 0) flag =true;
            if(now1[k-j-1]) --co;
            if(k-da[i]-j-1 >= 0 && now1[k-da[i]-j-1]) ++co;
        }
        // cout << co << endl;
        if(flag) ++ans;
    }
    // vdeb(pre);vdeb(bac);
    cout << n-ans << endl;
}