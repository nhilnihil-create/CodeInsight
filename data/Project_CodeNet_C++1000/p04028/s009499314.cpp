#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[10010], dpn[10010];
int main() {
	int N, ns;
	cin >> N;
	string S;
	cin >> S;
	ns = S.size();

	dp[ns] = 1;
	for (int i = N;i > 1;i--) {
		for (int j = max(0, ns - (N - i));j <= ns + (N - i);j++) {
			dpn[max(j - 1, 0)] += dp[j];
			dpn[j + 1] += dp[j] * 2;
		}
		for (int j = max(0, ns - (N - i) - 1);j <= ns + (N - i) + 1;j++) {
			dp[j] = dpn[j] % MOD;
			dpn[j] = 0;
		}
	}
	cout << (dp[0] + dp[1]) % MOD << endl;
}