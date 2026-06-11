#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, LG = 61;

int dp[N][LG];
long long a[N];
long long ans[N];

long long get(long long x, long long y) {
	return (x >> y) & 1;
}


int main() {
	int n, m;
	long long k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][0] = i;
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		swap(dp[x][0], dp[x - 1][0]);
	}
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i < n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
	ans[1] = a[1];
	for (int i = 2; i <= n; i++) {
		int x = i - 1;
		for (int j = 0; j < LG; j++) {
			if (get(k, j)) {
				x = dp[x][j];
			}
		}
		ans[i] = (long long) ans[i - 1] + a[x + 1] - a[x];
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
