/* In the name of Allah */
#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 5, P = 1e9 + 7;
int n, k, fact[N * N], rev[N * N], dp[N][N];

int power(int a, int b) {
	if (!b)
		return 1;
	int ans = power(a, b >> 1);
	ans = 1LL * ans * ans % P;
	if (b & 1)
		ans = 1LL * ans * a % P;
	return ans;
}

int C(int n, int k) {
	return 1LL * fact[n] * rev[k] % P * rev[n - k] % P;
}

void readInput() {
	cin >> n >> k;
}

void solve() {
	if (k == 1)
		return;
	fact[0] = rev[0] = dp[1][0] = dp[1][1] = 1;
	for (int i = 1; i < n * k; i++)
		rev[i] = power(fact[i] = 1LL * fact[i - 1] * i % P, P - 2);
	for (int i = 2; i <= n; i++) {
		for (int j = i; j; j--)
			dp[i][j] = (1LL * i * C(k * i - j - 1, k - 2) % P * dp[i - 1][j - 1] % P + dp[i][j + 1]) % P;
		dp[i][0] = dp[i][1];
	}
}

void writeOutput() {
	if (k == 1) {
		cout << "1\n";
		return;
	}
	cout << dp[n][0] << endl;
}

int main() {
	ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	readInput(), solve(), writeOutput();
	return 0;
}
