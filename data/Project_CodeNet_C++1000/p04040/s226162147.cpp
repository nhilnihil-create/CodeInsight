#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define MOD 1000000007LL
#define MAXN 200100

vector<long long> f(MAXN);


long long mul_inv(long long a, long long b)
{
	long long b0 = b, t, q;
	long long x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

long long division(long long a, long long b, long long p) {		// (a / b) mod p = ((a mod p) * (b^(-1) mod p)) mod p
	long long ans, inv;
	inv = mul_inv(b, p);
	ans = ((a % p) * inv) % p;
	return ans;
}

long long calc(long long n, long long k) {
	long long a = f[n], b = (f[k] * f[n - k]) % MOD;
	long long ans = division(a, b, MOD);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, m, i, j, k, a, b, ans, x, y;
	cin >> n >> m >> a >> b;
	
	f[0] = 1;
	for (i = 1; i < MAXN; i++) f[i] = (f[i - 1] * i) % MOD;

	ans = 0;
	for (i = 0; i < n - a; i++) {
		x = calc(b - 1 + i, i);
		y = calc(m - b - 1 + n - 1 - i, m - b - 1);

		ans = (ans + x * y) % MOD;
	}
	
	cout << ans << "\n";

	return 0;
}
