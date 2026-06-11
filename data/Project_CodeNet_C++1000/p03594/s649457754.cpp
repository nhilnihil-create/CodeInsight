#include <bits/stdc++.h>
 
typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;
 
using namespace std;
 
/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
 
int h, w, d;
int c[1200];
char s[1200][1200];
 
int main() {
	cin >> h >> w >> d;
	for (int i = 0; i < h + w - 1; ++i) {
		if (i >= d)
			c[i] = c[i - d] ^ 1;
		else
			c[i] = 0;
	}
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			int a = c[i + j] * 2 + c[i + (w - 1 - j)];
			if (a == 0)
				s[i][j] = 'G';
			else if (a == 1)
				s[i][j] = 'R';
			else if (a == 2)
				s[i][j] = 'B';
			else
				s[i][j] = 'Y';
		}
	for (int i = 0; i < h; ++i) {
		printf("%s\n", s[i]);
	}
	return 0;
}