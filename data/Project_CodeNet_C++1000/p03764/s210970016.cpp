#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int const MAX = 100005;
long long const MOD = 1000000007;
long long x[MAX], y[MAX];

long long mod_p(long long a, long long b) {
	return (a + b + 2 * MOD) % MOD;
}

long long mod_m(long long a, long long b) {
	return (a%MOD)*(b%MOD) % MOD;
}

long long func(long long p[], long long n) {
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long value = mod_m(n + 1 - 2 * i,p[i]);
		ans = mod_p(value, ans);
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int j = 1; j <= m; j++) {
		cin >> y[j];
	}
	cout << (func(x, n) * func(y, m)) % MOD << endl;
}
