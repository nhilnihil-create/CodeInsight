#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
 
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define emb emplace_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <typename T> inline T range(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
 
inline void setin(string s) {
    freopen(s.c_str(), "r", stdin);
}
 
inline void setout(string s) {
    freopen(s.c_str(), "w", stdout);
}
 
template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}
 
template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e4 + 15;
int n;

int temp[N], dp[N];

inline int add(int a, int b) {
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}

inline int mt(int a, int b) {
    return 1ll * a * b % mod;
}

inline void add_t(int &a, int b) {
    a = add(a, b);
}

inline int binpow(int n, int k) {
    int res = 1;
    while(k) {
        if(k & 1)
            res = mt(res, n);
        k >>= 1;
        n = mt(n, n);
    }
    return res;
}

string s;

main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> s;
    dp[0] = 1;
    for(int j = 1; j <= n; ++j) {
        memcpy(temp, dp, sizeof(temp));
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; ++i) {
            add_t(dp[max(0, i - 1)], temp[i]);
            add_t(dp[i + 1], add(temp[i], temp[i]));
        }
    }
    cout << mt(dp[s.size()], binpow(binpow(2, s.size()), mod - 2)) << endl;
    return 0;
}