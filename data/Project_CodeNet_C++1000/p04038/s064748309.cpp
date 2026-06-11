/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
double dot(complex<double> a, complex<double> b) {
	return a.real() * b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real() * b.imag() - a.imag() * b.real();
}
double leng(complex<double> a) {
	return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
double angles(complex<double> a, complex<double> b) {
	double cosine = dot(a, b) / (leng(a) * leng(b));
	double sine = gyaku_dot(a, b) / (leng(a) * leng(b));
	double kaku = acos(min((double)1.0, max((double)-1.0, cosine)));
	if (sine <= 0) {
		kaku = 2 * Ma_PI - kaku;
	}
	return kaku;
}
vector<int> convex_hull(vector<complex<double>> a) {
	vector<int> ans;
	double now_minnest = a[0].real();
	int now_itr = 0;
	REP(i, a.size()) {
		if (now_minnest > a[i].real()) {
			now_minnest = a[i].real();
			now_itr = i;
		}
	}
	ans.push_back(now_itr);
	complex<double> ba(0, 1);
	while (true) {
		int now_go = 0;
		double now_min = 0;
		double now_length = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa - now_min >= eps || (abs(goa - now_min) <= eps && (abs(a[i] - a[starter]) - now_length) >= eps)) {
					now_min = goa;
					now_go = i;
					now_length = abs(a[i] - a[starter]);
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}

#define ll long long
ll mo = 1000000007;
ll combi(ll N_, ll C_) {
	const int NUM_ = 4500001;
	static ll fact[NUM_ + 1], factr[NUM_ + 1], inv[NUM_ + 1];
	if (fact[0] == 0) {
		inv[1] = fact[0] = factr[0] = 1;
		for (int i = 2; i <= NUM_; ++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i = 1; i <= NUM_; ++i) fact[i] = fact[i - 1] * i % mo, factr[i] = factr[i - 1] * inv[i] % mo;
	}
	if (C_<0 || C_>N_) return 0;
	return factr[C_] * fact[N_] % mo * factr[N_ - C_] % mo;
}

long long dp[3000][3000];
long long omote[2000*2001];
long long inv[2000 * 2001];
long long n, k;
long long combination(long long a, long long b) {
	if (a < b) return 0;
	long long ans = omote[a];
	ans *= inv[b];
	ans %= MAX_MOD;
	ans *= inv[a - b];
	ans %= MAX_MOD;
	return ans;
}
int main() {
	omote[0] = 1;
	inv[0] = 1;
	omote[1] = 1;
	inv[1] = 1;
	for (long long i = 2; i <= 2000 * 2000; ++i) {
		omote[i] = omote[i - 1] * i;
		omote[i] %= MAX_MOD;
		inv[i] = inv[MAX_MOD % i] * (MAX_MOD - MAX_MOD / i) % MAX_MOD;
	}
	for (long long i = 2; i <= 2000 * 2000; ++i) {
		inv[i] *= inv[i - 1];
		inv[i] %= MAX_MOD;
	}
	cin >> n >> k;
	if (k == 1) {
		cout << 1 << endl;
		return 0;
	}
	dp[0][1] = 1;
	for (int i = 2; i <= n; ++i) {
		long long go = combination(i * (k - 1) - 1, k - 2);
		dp[0][i] = dp[0][i - 1] * go % MAX_MOD;
	}
	for (int x = 1; x <= n; x++) {
		if (x == 1) dp[1][1] = 1;
		else dp[x][x] = dp[x - 1][x];
		for (int y = x + 1; y <= n; ++y) {
			long long go = combination(x + y * (k - 1) - 1, k - 2);
			dp[x][y] = (dp[x - 1][y] + dp[x][y - 1] * go) % MAX_MOD;
		}
	}
	long long ans = dp[n][n] * omote[n]%MAX_MOD;
	cout << ans%MAX_MOD << endl;
}
