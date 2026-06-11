#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
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
#include <random>
#include <iomanip>
#include <bitset>
                      
using namespace std;
                      
template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}
                      
template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}

#define int long long
#define ghost signed
#define left left228
#define right right228
#define prev prev228
#define list list228
#define next next228

const int MOD = 1e9 + 7;
const int N = 200 * 1000 + 228;

int mod(int x) {
	return (x % MOD + MOD) % MOD;
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int H, W, A, B;
int f[N], rf[N];

int fp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mod(res * a);
		a = mod(a * a);
		b >>= 1;
	}
	return res;
}


void pre() {
	f[0] = 1;
	for (int i = 1; i <= H + W; ++i) f[i] = mod(f[i - 1] * i);
	for (int i = 0; i <= H + W; ++i) rf[i] = fp(f[i], MOD - 2);
}

int C(int n, int k) {
	return mod(f[n] * mod(rf[k] * rf[n - k]));
}

ghost main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> H >> W >> A >> B;
	pre();
	int res = 0;
	for (int j = B + 1; j <= W; ++j) {
		add(res, mod(C(H - A - 1 + j - 1, j - 1) * C(A - 1 + W - j, A - 1)));
	}
	cout << res << '\n';
	return 0;
} // kek;






