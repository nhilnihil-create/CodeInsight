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
char ss[100000], tt[100000];
int main() {
	
	//E
	string s;
	string t;
	cin >> s;
	cin >> t;
	int i;
	ss[0] = s[0];
	for (i = 1; i < s.size(); i++) {

		if (ss[i - 1] == 'A') {
			if (s[i] == 'A') {
				ss[i] = 'B';
			}
			else {
				ss[i] = ' ';
			}
		}
		else if (ss[i - 1] == 'B') {
			if (s[i] == 'A') {
				ss[i] = ' ';
			}
			else {
				ss[i] = 'A';
			}
		}
		else {
			ss[i] = s[i];
		}

	}
	tt[0] = t[0];
	for (i = 1; i < t.size(); i++) {

		if (tt[i - 1] == 'A') {
			if (t[i] == 'A') {
				tt[i] = 'B';
			}
			else {
				tt[i] = ' ';
			}
		}
		else if (tt[i - 1] == 'B') {
			if (t[i] == 'A') {
				tt[i] = ' ';
			}
			else {
				tt[i] = 'A';
			}
		}
		else {
			tt[i] = t[i];
		}

	}

	int q;
	cin >> q;
	int a, b, c, d;
	char t1, s1;
	for (i = 0; i < q; i++) {
		cin >> a >> b >> c >> d;

		if (a == 1) {
			s1 = ss[b - 1];
		}
		else {
			if (ss[b - 1] == ss[a - 2]) {
				s1 = ' ';
			}
			if (ss[a - 2] == ' ') {
				s1 = ss[b - 1];
			}
			else if (ss[b - 1] == 'A' && ss[a - 2] == 'B') {
				s1 = 'B';
			}
			else if (ss[b - 1] == 'B' && ss[a - 2] == 'A') {
				s1 = 'A';
			}
			else if (ss[b - 1] == ' ' && ss[a - 2] == 'A') {
				s1 = 'B';
			}
			else if (ss[b - 1] == ' ' && ss[a - 2] == 'B') {
				s1 = 'A';
			}
				
		}
		if (c == 1) {
			t1 = tt[d - 1];
		}
		else {
			if (tt[d - 1] == tt[c - 2]) {
				t1 = ' ';
			}
			if (tt[c - 2] == ' ') {
				t1 = tt[d - 1];
			}
			else if (tt[d - 1] == 'A' && tt[c - 2] == 'B') {
				t1 = 'B';
			}
			else if (tt[d - 1] == 'B' && tt[c - 2] == 'A') {
				t1 = 'A';
			}
			else if (tt[d - 1] == ' ' && tt[c - 2] == 'A') {
				t1 = 'B';
			}
			else if (tt[d - 1] == ' ' && tt[c - 2] == 'B') {
				t1 = 'A';
			}

		}
		if (s1 == t1) {
			cout  << "YES" << endl;
		}
		else {
			cout  << "NO" << endl;
		}
	}

	return 0;
	//D
	/*
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
	return 0;*/

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
