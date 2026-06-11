#include "bits/stdc++.h"
using namespace std;

constexpr long long int mod = 1e9 + 7;

int main() {
	long long int n, m;
	cin >> n >> m;

	long long ans = 1;

	if (n > m) {
		while (1) {
			if (n == 0 || m == 0) break;
			ans = ans % mod * n--;
			ans = ans % mod * m--;
		}
	}
	else {
		while (1) {
			if (n == 0 || m == 0) break;
			ans = ans % mod * m--;
			ans = ans % mod * n--;
		}
	}

	if (n == m) ans = ans % mod * 2;
	else if (n + m > 1) ans = 0;

	cout << ans % mod << endl;
}