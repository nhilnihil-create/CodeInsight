#include <iostream>
using namespace std;

const int N = 2005, mod = 1000 * 1000 * 1000 + 7;


long long fac[N * N];
long long facp[N * N];
long long dp[N][N];
long long ps[N][N];

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}
int chs(int x, int y) {
	long long ans = fac[x];
	ans *= facp[y];
	ans %= mod;
	ans *= facp[x - y];
	ans %= mod;
	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	fac[0] = 1;
	for (int i = 1; i <= n * k; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	facp[n * k] = po(fac[n * k], mod - 2);
	facp[0] = 1;
	for (int i = n * k - 1; i; i--) {
		facp[i] = facp[i + 1] * (i + 1);
		facp[i] %= mod;
	}
	dp[1][1] = 1;
	ps[1][1] = 1;
//	cout << chs(4, 2) << endl;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = ps[i - 1][i - 1];
			if (j - 2 >= 0) {
				dp[i][j] -= ps[i - 1][j - 2] - mod;
				dp[i][j] %= mod;
			}
			dp[i][j] *= i;
			dp[i][j] %= mod;
			dp[i][j] *= chs(i * k - j - 1, k - 2);
			dp[i][j] %= mod;
		//	cout << i << " " << j << " " << dp[i][j] << endl;
			ps[i][j] = ps[i][j - 1] + dp[i][j];
			ps[i][j] %= mod;
		}
	}
	cout << ps[n][n];
	return 0;
}
