#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int64_t sub(int64_t n) {
	int64_t retval = 1;

	for (int64_t i = n; i > 0; i--) {
		retval = retval % MOD * i % MOD;
	}

	return retval;
}

int main() {
	int64_t N, M;
	cin >> N >> M;

	int64_t d = abs(N - M);
	int64_t ans = 0;

	int64_t n, m;
	n = sub(N);
	m = sub(M);
	if (d <= 1) ans = n * m % MOD;
	if (!d) ans = ans % MOD * 2 % MOD;
	
	cout << ans << endl;
}