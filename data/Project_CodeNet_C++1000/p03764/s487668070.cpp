#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<vector>
int az[26];
using namespace std;
long long modpow(long long a, long long n, long long mod);
long long modinv(long long a, long long mod);
long long int x[100000], y[100000];
long long int MOD = 1000000007;

int main() {
	
	//D
	int n, m;
	int i;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> x[i];
	}
	//sort(x, x + n);
	for (i = 0; i < m; i++) {
		cin >> y[i];
	}
	//sort(y, y + n);
	long long int xsum = 0, ysum = 0;
	long long int l = x[n - 1] - x[0];
	xsum = l % MOD;
	l = l % MOD;
	for (i = 1; i < n; i++) {
		l = l + x[n - 1 - i] - x[i] + MOD;
		l = l % MOD;
		xsum = xsum + l;
		xsum = xsum % MOD;
	}
	l = y[m - 1] - y[0];
	ysum = l % MOD;
	l = l % MOD;
	for (i = 1; i < m; i++) {
		l = l + y[m - 1 - i] - y[i] + MOD;
		l = l % MOD;
		ysum = ysum + l;
		ysum = ysum % MOD;
	}
	cout << (xsum * ysum) % MOD << endl;
	return 0;

	//C
	/*
	string s;
	int n;
	cin >> n;
	int i, j, k;
	
	for (j = 0; j < 26; j++) {
		az[j] = 100;
	}
	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < 26; j++) {
			k = count(s.cbegin(), s.cend(), 'a' + j);
			az[j] = min(k, az[j]);
		}
	}
	char c;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < az[i]; j++) {
			c =  'a' + i;
			cout << c;	
		}
	}
	cout << endl;
	return 0;
	*/
}

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}
