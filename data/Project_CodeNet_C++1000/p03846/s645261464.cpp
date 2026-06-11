#include <bits/stdc++.h>
using namespace std;
//mod
const int mod = 1e9 + 7;
int pow(int x, int y) { //x^y
	int rv = 1;
	for (; y > 0; y >>= 1, x = (long long) x * x % mod)
		if (y & 1)
			rv = (long long) rv * x % mod;
	return rv;
}
const int nm = 1e5;
int n, c[nm];
int main() {
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		c[a]++;
	}
	bool b = ~n & 1 | c[0] == 1;
	for (int i = n - 1; i > 0; i -= 2)
		if (c[i] != 2) {
			b = 0;
			break;
		}

	cout << (b ? pow(2, n / 2) : 0) << endl;

}
