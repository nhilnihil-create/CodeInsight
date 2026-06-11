#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;


const long long int mod = 1000000007, INF = 100000000000000;

//階乗先に計算
long long int kaizyou[200005] = { 1 };
long long int kai(long long int a, long long int b, long long int mod) {
	long long int tmp = 1;
	for (long long int i = a; i <= b; i++) {
		tmp *= i;
		tmp %= mod;

		kaizyou[i] = tmp;
	}
	return tmp;
}


//累乗(繰り返し2乗法)　aのb乗(mod)を求める。
long long int rui(long long int a, long long int b, long long mod) {
	int memo[65] = {};
	long long int A[65] = {};
	long long int tmp = 1;
	for (int i = 0; i < 65; i++) {
		memo[i] = b % 2;
		b /= 2;
	}

	A[0] = a;
	A[0] %= mod;

	for (int i = 1; i < 65; i++) {
		A[i] = A[i - 1] * A[i - 1];
		A[i] %= mod;
	}
	for (int i = 0; i < 65; i++) {
		if (memo[i] == 1) {
			tmp *= A[i];
			tmp %= mod;
		}
	}
	tmp %= mod;
	return tmp;
}

//コンビネーション計算
long long int comb(long long int n, long long int r, long long int mod) {
	long long int tmp;

	tmp = (kaizyou[n] * rui(kaizyou[r], mod - 2, mod)) % mod;
	tmp *= rui(kaizyou[n - r], mod - 2, mod);
	tmp %= mod;
	if (tmp < 0) { tmp = (mod - tmp) % mod; }
	return tmp;
}



long long int n, k, h, a,b,w, res = 0, num[200000] = {}, sum[200003] = {}, dp[150][70000] = {};
int main() {
	cout << fixed << setprecision(10);
	kai(1, 200000, mod);
	cin >> h >> w >> a >> b;
	for (int i = 0; i <= h - a && i <= w - b - 1; i++) {
		res+=comb(h - a +b-1, b  + i, mod)* comb(a +w-b-1, w - b - 1-i, mod);
		res %= mod;
	}
	cout << res;
}
