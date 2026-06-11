// O O O O O O O O O O O O O O O OO O OO O OO O O O TTCH O TTTCH O TTTCH O O O O
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
// #include <random>
#include <iomanip>
#include <bitset>
#include <cassert>
 
using namespace std;

#define y1 y11
#define double long double
#define less less228
#define left left228
#define right right228
#define list list228
#define all(v) v.begin(), v.end()
 
 
 
template<typename T> void uin(T &a, T b) {
    if (b < a) a = b;
}
template<typename T> void uax(T &a, T b) {
    if (b > a) a = b;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[a] ^= 1;
        cnt[b] ^= 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
// RU_023
 
/*
4 2
2 1 3 3
1 2 4 3
6 1 7 4
5 3 7 5

3 3
1 1 1 1
1 2 1 2
1 3 1 3

*/