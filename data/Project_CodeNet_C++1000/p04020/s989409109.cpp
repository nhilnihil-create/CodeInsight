#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100100;

int n;
ll dp[N][2], rem[N][2], a[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];	
	dp[1][0] = a[1] / 2;
	rem[1][0] = a[1] % 2;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i] / 2;
		ll add1 = (a[i] - 1) / 2 + rem[i - 1][0];
		ll add2 = (a[i] - 1) / 2 + rem[i - 1][1];
		if (a[i] == 0) add1 = 0, add2 = 0;
		dp[i][1] = max(dp[i - 1][0] + add1, dp[i - 1][1] + add2);
		rem[i][0] = a[i] % 2;
		if (a[i] > 0) rem[i][1] = (a[i] - 1) % 2;
	}
	cout << max(dp[n][0], dp[n][1]) << '\n';
}
