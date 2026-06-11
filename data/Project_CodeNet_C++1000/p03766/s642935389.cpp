#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add(int &x,int y) {
	x += y; if (x >= mod) x -= mod;
}

int mul(int x,int y) {
	return 1LL * x * y % mod;
}

int n;
int f[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	f[0] = 1; f[1] = n; f[2] = mul(n, n);
	int sum = f[0] + f[1] + f[2];
	while (sum >= mod) sum -= mod;
	for (int i = 3; i <= n; ++i) {
		add(f[i], mul(n - 1, n - 1));
		add(f[i], sum);
		add(f[i], mod - f[i - 2]);
		add(f[i], n - i + 1);
		add(sum, f[i]);
	}
	cout << f[n] << '\n';
}
