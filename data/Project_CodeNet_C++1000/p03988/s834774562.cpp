#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
#include <cmath>
using namespace std;
long long gcd(long long a, long long b) {
	if (a < b) gcd(b, a);
	long long  r;
	while ((r = a%b)) {
		a = b;
		b = r;
	}
	return b;
}
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t*b; swap(a, b);
		u -= t*v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}
namespace NTT {
	const int MOD = 998244353;  // to be set appropriately
	const long long PR = 3;     // to be set appropriately

	void trans(vector<long long> &v, bool inv = false) {
		int n = (int)v.size();
		for (int i = 0, j = 1; j < n - 1; j++) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (i > j) swap(v[i], v[j]);
		}
		for (int t = 2; t <= n; t <<= 1) {
			long long bw = modpow(PR, (MOD - 1) / t, MOD);
			if (inv) bw = modinv(bw, MOD);
			for (int i = 0; i < n; i += t) {
				long long w = 1;
				for (int j = 0; j < t / 2; ++j) {
					int j1 = i + j, j2 = i + j + t / 2;
					long long c1 = v[j1], c2 = v[j2] * w % MOD;
					v[j1] = c1 + c2;
					v[j2] = c1 - c2 + MOD;
					while (v[j1] >= MOD) v[j1] -= MOD;
					while (v[j2] >= MOD) v[j2] -= MOD;
					w = w * bw % MOD;
				}
			}
		}
		if (inv) {
			long long inv_n = modinv(n, MOD);
			for (int i = 0; i < n; ++i) v[i] = v[i] * inv_n % MOD;
		}
	}

	// C is A*B
	vector<long long> mult(vector<long long> A, vector<long long> B) {
		int size_a = 1; while (size_a < A.size()) size_a <<= 1;
		int size_b = 1; while (size_b < B.size()) size_b <<= 1;
		int size_fft = max(size_a, size_b) << 1;

		vector<long long> cA(size_fft, 0), cB(size_fft, 0), cC(size_fft, 0);
		for (int i = 0; i < A.size(); ++i) cA[i] = A[i];
		for (int i = 0; i < B.size(); ++i) cB[i] = B[i];

		trans(cA); trans(cB);
		for (int i = 0; i < size_fft; ++i) cC[i] = cA[i] * cB[i] % MOD;
		trans(cC, true);

		vector<long long> res((int)A.size() + (int)B.size() - 1);
		for (int i = 0; i < res.size(); ++i) res[i] = cC[i];
		return res;
	}
};
typedef pair<int, int> p;
typedef pair<int, p> pai;
const int maxn = 1 << 24;
int n2;
long long dat[2 * maxn - 1];
void init(int n_) {
	n2 = 1;
	while (n2 < n_)n2 *= 2;
	for (int i = 0; i < 2 * n2 - 1; i++) {
		dat[i] = LLONG_MIN/2;
	}
}
void update(long long  k, long long a) {
	k += n2 - 1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}
long long query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l)return LLONG_MIN/2;
	if (a <= l&&r <= b)return dat[k];
	else {
		long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
}
long long mod = 998244353;
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int num[103] = { 0 };
	int maxi = 0;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		num[tmp] += 1;
		maxi = max(tmp, maxi);
	}
	int judge = 0;
	if (maxi % 2 == 0) {
		for (int i = maxi; i >= maxi / 2 + 1; i--) {
			if (num[i] < 2)judge = 1;
		}
		if (num[maxi/2] != 1)judge = 1;
		for (int i = 1; i <= maxi / 2 - 1; i++) {
			if (num[i] >= 1)judge = 1;
		}
	}
	else {
		for (int i = maxi; i >= (maxi + 1) / 2 + 1; i--) {
			if (num[i] < 2)judge = 1;
		}
		if (num[(maxi + 1) / 2] != 2)judge = 1;
		for (int i = 1; i <= maxi / 2; i++) {
			if (num[i] >= 1)judge = 1;
		}
	}
	if (judge == 1)cout << "Impossible";
	else cout << "Possible";
}
