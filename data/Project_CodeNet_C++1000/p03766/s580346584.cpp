#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> II;

const int N = (int) 1e6 + 10;
const int P = (int) 1e9 + 7;
int n, dp[N];

int main() {
	scanf("%d", &n);
	int s = dp[1] = n; dp[0] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = (s + (n - 1ll) * (n - 1ll) + n - i + 2) % P;
		dp[i] = (dp[i] - dp[i - 2] + P) % P;
		s = (s + dp[i]) % P;
	}
	//for (int i = 1; i <= n; ++i) cerr << dp[i] << endl;
	cout << dp[n];
	return 0;
}